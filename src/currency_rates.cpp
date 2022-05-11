#include "currency_rates.h"

CurrencyRates::CurrencyRates()
{
}

CurrencyRates::~CurrencyRates()
{
}

void CurrencyRates::addUsdRate(CurrencyType currencyType, MultiPrecFloat rate)
{
    currencyRates[currencyType] = rate;
}

MultiPrecFloat CurrencyRates::getUsdRate(CurrencyType currencyType) const
{
    std::unordered_map<CurrencyType, MultiPrecFloat>::const_iterator itr = currencyRates.find(currencyType);
    return (itr == currencyRates.end()) ? 0 : itr->second;
}