#ifndef APP_CONST_H
#define APP_CONST_H

#include <boost/multiprecision/cpp_dec_float.hpp>

static const unsigned numOfPrecision = 50;
using MultiPrecFloat = boost::multiprecision::cpp_dec_float_50;
enum CurrencyType {BTC, ETH, DOGE};

#endif