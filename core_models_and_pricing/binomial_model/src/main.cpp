#include<iostream>
#include"payoff.h"
#include"loader.h"
#include"tree.h"
#include"option_chain.h"

int main(){
    auto data = loadCSV("option-chain-ED-NIFTY-04-Aug-2026.csv");
    OptionChainRow option = parseRow(data[2]);
    std::cout << "Strike   : " << option.strike << '\n';
    std::cout << "Call LTP : " << option.callLTP << '\n';
    std::cout << "Call IV  : " << option.callIV << '\n';
    std::cout << "Put LTP  : " << option.putLTP << '\n';
    std::cout << "Put IV   : " << option.putIV << '\n';
    Binomial_Tree tree(100, 0.2, 0.05, 1.0, 3);
    tree.buildStockTree();
    tree.printStockTree();
}