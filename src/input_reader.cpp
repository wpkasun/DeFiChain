#include "app_consts.h"
#include "currency_converter.h"
#include "input_reader.h"
#include "live_rates_reader.h"
#include "printer.h"

#include <iostream>
#include <fstream>

InputReader::InputReader()
{
}

InputReader::~InputReader()
{
}

void InputReader::readInputFile(const std::string& filePath)
{
	std::ifstream ifs(filePath);
    if (ifs.is_open()) {
        CurrencyRates currencyRates;
        std::string line;
        if (std::getline(ifs, line))
        {
            if (line == "CURRENT")
            {
                MultiPrecFloat btcUsdRate, ethUsdRate, dogeUsdRate;
                LiveRatesReader liveRatesReader;
                if (liveRatesReader.getLiveRates(btcUsdRate, ethUsdRate, dogeUsdRate))
                {
                    currencyRates.addUsdRate(BTC, btcUsdRate);
                    currencyRates.addUsdRate(ETH, ethUsdRate);
                    currencyRates.addUsdRate(DOGE, dogeUsdRate);
                }
                else
                {
                    std::cout << "Failed taking live current spot rates." << std::endl;
                    return;
                }

            }
            else
            {
                std::istringstream iss(line);
                std::string word;
                if (std::getline(iss, word, ' '))
                {
                    MultiPrecFloat rate(word);
                    currencyRates.addUsdRate(BTC, rate);
                }
                if (std::getline(iss, word, ' '))
                {
                    MultiPrecFloat rate(word);
                    currencyRates.addUsdRate(ETH, rate);
                }
                if (std::getline(iss, word, ' '))
                {
                    MultiPrecFloat rate(word);
                    currencyRates.addUsdRate(DOGE, rate);
                }
            }
        }
        CurrencyConverter currencyConverter(currencyRates);
        while (std::getline(ifs, line)) {
            std::istringstream iss(line);
            std::string word;
            if (std::getline(iss, word, ' '))
            {
                MultiPrecFloat ethSaleRate(word);
                if (std::getline(iss, word, ' '))
                {
                    std::size_t decPlaces = stoi(word);
                    if (std::getline(iss, word, ' '))
                    {
                        CurrencyType currencyType = ETH;
                        if (word == "BTC")
                        {
                            currencyType = BTC;
                        }
                        else if (word == "DOGE")
                        {
                            currencyType = DOGE;
                        }
                        if (std::getline(iss, word, ' '))
                        {
                            MultiPrecFloat amount(word);
                            MultiPrecFloat saleValue = currencyConverter.getSaleValue(ethSaleRate, currencyType, amount);
                            Printer printer;
                            printer.print(saleValue, decPlaces);
                        }
                    }
                }
            }
        }
        ifs.close();
    }
    else {
        std::cout << "Input file: \"" << filePath << "\"" "does not exist." << std::endl;
    }
}