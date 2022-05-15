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
    MultiPrecFloat ethRate = currencyRates.getUsdRate(ETH);
    assert((ethRate > 0) && "Currenry rates should have valid value.");
    return srcCurrencyRate / ethRate;
}

MultiPrecFloat CurrencyConverter::getSaleValue(MultiPrecFloat ethSaleRate, CurrencyType currencyType, MultiPrecFloat amount)
{
    return getEthRate(currencyType) * ethSaleRate * amount;
}
