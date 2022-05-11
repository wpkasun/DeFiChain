// This class keep the currency rate to USD for each currency types

#ifndef CURRENCY_RATES_H
#define CURRENCY_RATES_H

#include "app_consts.h"

#include <unordered_map>

class CurrencyRates
{
public:
	CurrencyRates();
	~CurrencyRates();
    void addUsdRate(CurrencyType currencyType, MultiPrecFloat rate);
    MultiPrecFloat getUsdRate(CurrencyType currencyType) const;

private:
    std::unordered_map<CurrencyType, MultiPrecFloat> currencyRates;
};

#endif