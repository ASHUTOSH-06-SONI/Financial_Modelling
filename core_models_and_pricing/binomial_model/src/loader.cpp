#include"loader.h"
#include<fstream>
#include<sstream>
#include<iostream>
std::vector<std::vector<std::string>> loadCSV(const std::string& filename){
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr<<"Can't open file: "<<std::endl;
        return {};
    }
    std::vector<std::vector<std::string>> data;
    std::string line;
    while(std::getline(file,line)){
        std::vector<std::string> row;
        bool insideQuotes = false;
        std::string cell;
        for(char c: line){
            if(c == '"'){
                insideQuotes = !insideQuotes;
            }else if(c == ',' && !insideQuotes){
                row.push_back(cell);
                cell.clear();
            }else{
                cell+=c;
            }
        }
        row.push_back(cell);
        data.push_back(row);
    } 
    return data;  
}
/*
int main()
{
    auto data = loadCSV("option-chain-ED-NIFTY-04-Aug-2026.csv");
    for (int i = 0; i < 4 && i < data.size(); i++)
    {
        std::cout<< "Row "<<i<<std::endl;
        for (int j = 0; j < data[i].size(); j++){
            std::cout<<j<<" : "<<data[i][j]<<std::endl;
        }
        std::cout << "------------------------\n";
    }
    return 0;
}
*/