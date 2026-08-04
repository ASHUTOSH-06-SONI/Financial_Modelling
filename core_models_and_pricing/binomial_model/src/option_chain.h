#ifndef OPTION_CHAIN_H
#define OPTION_CHAIN_H
#include<string>
#include<vector>
struct OptionChainRow{
    double strike;
    double callLTP;
    double callIV;
    double putLTP;
    double putIV;
    double maturity;
};
OptionChainRow parseRow(const std::vector<std::string>& row);

#endif
