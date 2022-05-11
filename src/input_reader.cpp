#include "app_consts.h"
#include "currency_converter.h"
#include "input_reader.h"
#include "printer.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

InputReader::InputReader()
{
}

InputReader::~InputReader()
{
}

void InputReader::readInputFile(const std::string& fileName)
{
	std::ifstream ifs(fileName);
    if (ifs.is_open()) {
        CurrencyRates currencyRates;
        std::string line;
        if (std::getline(ifs, line))
        {
            if (line == "CURRENT")
            {
                std::cout << "Live rates not implemented yet." << line << std::endl;
                ifs.close();
                return;
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
            //std::cout << line << std::endl;
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
        std::cout << "Input file: \"" << fileName << "\"" "does not exist." << std::endl;
    }
}