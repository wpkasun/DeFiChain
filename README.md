## DeFiChain - Multi-currency Token Sale ##
In blockchain & cryptocurrency, we are constantly dealing with huge numbers, for example Ether (ETH) with 18 decimal places.

## Problem statement ##
Supposedly there's a token sale that sells token X for token Y. For ease of discussion, let's call token X (token for sale), SALE token and token Y (base currency) ETH.

This simple CLI app is to allow us to quickly determine the amount of SALE token a given amount of ETH would fetch. ETHSALE rate is the rate of amount of SALE that 1 ETH can get and is provided as an input with the app.

A token sale may also want to accept another cryptocurrency other than ETH, such as BTC and DOGE. As the price of SALE is fixed at ETH, and BTCUSD price fluctuates according to market, BTCSALE has to be computed based on market rate of BTCUSD and ETHUSD.

## Example ##
ETHSALE rate is determined to be 1 ETH to 5000 SALE at start of app.
BTCUSD is given as 10000, ETHUSD is 200. It can be worked out that BTCETH is thus 50.
A purchase with 5 ETH would yield 25,000 SALE
A purchase with 2.4 BTC would yield 600,000 SALE
Input and output
Input is given from standard input.

First line provides the exchange rates for BTC, ETH and DOGE paired with USD.

From second line onwards, each line represents a unique standalone case. Each line would be in the following format, expected output would be the amount of SALE expected given the ETH purchase amount, rounded down to a given number of decimal places for SALE.

Notes:

Only the following 3 different possible input currencies are supported: BTC, ETH, and DOGE. This cannot handle arbitrary pairings. Price should always be provided with USD base.
SALE rate will always be provided in ETHSALE, i.e. how many SALE per 1 ETH received.
<BTCUSD rate> <ETHUSD rate> <DOGEUSD rate>
<ETHSALE rate> <SALE decimal places> <Purchase currency> <BTC/ETH/DOGE purchase amount>
<ETHSALE rate> <SALE decimal places> <Purchase currency> <BTC/ETH/DOGE purchase amount>
<ETHSALE rate> <SALE decimal places> <Purchase currency> <BTC/ETH/DOGE purchase amount>
...

## Sample input and usage ##
The following sample input provides the following market rates:

BTCUSD: 3825.281112
ETHUSD: 138.8911
DOGEUSD: 0.00198422341298374987
Sample input (input.txt):

3825.281112 138.8911 0.00198422341298374987
1.5 3 ETH 3.5
1.5 3 BTC 3.5
1.5 3 DOGE 3.5
1.5 3 DOGE 350000
1.5 1 ETH 3.5
6540825.876543210987654325 18 ETH 992465.123456789012345678
6540825.876543210987654325 18 DOGE 992465.123456789012345678
6540825.876543210987654325 18 BTC 992465.123456789012345678
Usage with output for the above input:

$ ./run < input.txt
5.250
144.593
0.000
7.500
5.2
6491541561072.818099748528072316
92739338.602961358374866197
178787347219043.160674658985510029
Note: Your results may vary slightly depending on order of operation.

## Live rates ##
Support the current market spot rates of cryptocurrency by integrating with publicly available price feed API providers. For live current spot rates, first line of the INPUT would simply be the word CURRENT.

Sample input and usage:
Sample input for current spot rates (input.txt):

CURRENT
1.5 3 ETH 3.5
1.5 3 BTC 3.5
1.5 3 DOGE 3.5
1.5 3 DOGE 350000
1.5 1 ETH 3.5
6540825.876543210987654325 18 ETH 992465.123456789012345678
6540825.876543210987654325 18 DOGE 992465.123456789012345678
6540825.876543210987654325 18 BTC 992465.123456789012345678

'CoinGecko' is used as the price feed providers in this app.

Notes:
'curl', 'boost' and 'gtest' liraries are used as external dependencies here.

The final output is precised up to the number of decimal places, rounded down for any extra decimal places.

Few unit test are included, Read the README.md inside test directory.

## How to build and run ##

Dependencies:
1. boost (sudo apt-get install libboost-all-dev)
2. libcurl (sudo apt-get install libcurl4-gnutls-dev)

Instructions to buid and run:
1. make
2. ./DeFiChain <input_file>
