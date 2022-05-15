#include "live_rates_reader.h"

#include <iostream>
#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <curl/curl.h>

LiveRatesReader::LiveRatesReader()
{
}

LiveRatesReader::~LiveRatesReader()
{
}

size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

bool LiveRatesReader::getLiveRates(MultiPrecFloat &btcUsdRate, MultiPrecFloat &ethUsdRate, MultiPrecFloat &dogeUsdRate)
{
    bool success(false);
    CURL* curl = curl_easy_init();
    if (curl) {
        // Get lived rate from coingecko api
        const std::string url("https://api.coingecko.com/api/v3/simple/price?ids=bitcoin,ethereum,dogecoin&vs_currencies=usd");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        struct curl_slist *list = NULL;
        list = curl_slist_append(list, "accept: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        CURLcode res = curl_easy_perform(curl);

        if (res == 0) //no error from api
        {
            // Parse the json response
            std::stringstream ss;
            ss.str (response);
            boost::property_tree::ptree pt;
            boost::property_tree::read_json(ss, pt);
            MultiPrecFloat btcRate(pt.get_child("bitcoin.usd").data());
            MultiPrecFloat ethRate(pt.get_child("ethereum.usd").data());
            MultiPrecFloat dogeRate(pt.get_child("dogecoin.usd").data());
            btcUsdRate = btcRate;
            ethUsdRate = ethRate;
            dogeUsdRate = dogeRate;
            success = true;
        }

        // Curl cleanup
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        curl = NULL;
    }
    return success;
}
