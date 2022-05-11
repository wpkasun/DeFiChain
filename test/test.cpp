#include "app_consts.h"
#include "currency_converter.h"
#include "currency_rates.h"
#include "input_reader.h"
#include "printer.h"

#include <gtest/gtest.h>
 
TEST(CurrencyRatesTest, case0) 
{
    CurrencyRates currencyRates;
    currencyRates.addUsdRate(BTC, 3825.281112);
    currencyRates.addUsdRate(ETH, 138.8911);
    MultiPrecFloat btcRate = currencyRates.getUsdRate(BTC);
    MultiPrecFloat dogeRate = currencyRates.getUsdRate(DOGE);
    EXPECT_EQ(btcRate, 3825.281112);
    EXPECT_EQ(dogeRate, 0);
}

TEST(CurrencyConverterTest, case0) 
{
    CurrencyRates currencyRates;
    currencyRates.addUsdRate(BTC, 3825.281112);
    currencyRates.addUsdRate(ETH, 138.8911);
    currencyRates.addUsdRate(DOGE, 0.00198422341298374987);
    CurrencyConverter currencyconverter(currencyRates);
    MultiPrecFloat btcSaleValue = currencyconverter.getSaleValue(1.5, ETH, 3.5);
    EXPECT_EQ(btcSaleValue, 5.250);
}

TEST(PrinterTest, case0) 
{
    testing::internal::CaptureStdout();
    Printer printer;
    printer.print(178787347219043.160674656449440139, 6);
    std::string output(testing::internal::GetCapturedStdout());
    EXPECT_EQ(output, std::to_string(178787347219043.156250) + "\n");
}

TEST(InputReaderTest, case0) 
{
    testing::internal::CaptureStdout();
    InputReader inputReader;
    inputReader.readInputFile("input.txt");
    std::string output(testing::internal::GetCapturedStdout());
    std::string expected("5.250\n144.593\n0.000\n7.500\n5.2\n6491541561072.818099748528072316\n92739338.602961360930566195\n178787347219043.160674656449440139\n");
    EXPECT_EQ(output, expected);
}
 
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}