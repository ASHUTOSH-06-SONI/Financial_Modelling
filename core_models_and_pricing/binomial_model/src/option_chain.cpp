#include"option_chain.h"
#include"utils.h"
OptionChainRow parseRow(const std::vector<std::string>& row){
    OptionChainRow parsed;
    parsed.strike = toDouble(row[11]);
    parsed.callIV = toDouble(row[4]);
    parsed.callLTP= toDouble(row[5]);
    parsed.putIV  = toDouble(row[17]); 
    parsed.putLTP = toDouble(row[18]);
    return parsed;
}