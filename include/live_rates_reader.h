#ifndef LIVE_RATES_READER_H
#define LIVE_RATES_READER_H

#include "app_consts.h"

class LiveRatesReader
{
public:
	LiveRatesReader();
	~LiveRatesReader();
	bool getLiveRates(MultiPrecFloat &btcUsdRate, MultiPrecFloat &ethUsdRate, MultiPrecFloat &dogeUsdRate);

private:

};

#endif
