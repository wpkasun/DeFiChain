#ifndef CURRENCY_CONVERTER_H
#define CURRENCY_CONVERTER_H

#include "app_consts.h"
#include "currency_rates.h"

class CurrencyConverter
{
public:
	CurrencyConverter(CurrencyRates currencyRates);
	~CurrencyConverter();
    MultiPrecFloat getEthRate(CurrencyType currencyType);
    MultiPrecFloat getSaleValue(MultiPrecFloat ethSaleRate, CurrencyType currencyType, MultiPrecFloat amount);

private:
    CurrencyRates currencyRates;
};

#endif
