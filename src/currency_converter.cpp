#include "currency_converter.h"

#include <assert.h>

CurrencyConverter::CurrencyConverter(CurrencyRates currencyRates) : currencyRates(currencyRates)
{
}

CurrencyConverter::~CurrencyConverter()
{
}

MultiPrecFloat CurrencyConverter::getEthRate(CurrencyType currencyType)
{
    MultiPrecFloat srcCurrencyRate = currencyRates.getUsdRate(currencyType);
    return srcCurrencyRate / currencyRates.getUsdRate(ETH) ;
}

MultiPrecFloat CurrencyConverter::getSaleValue(MultiPrecFloat ethSaleRate, CurrencyType currencyType, MultiPrecFloat amount)
{
    return getEthRate(currencyType) * ethSaleRate * amount;
}