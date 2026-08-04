#include "tree.h"
#include <cmath>
#include<iostream>
#include <fstream>

void Binomial_Tree::exportStockTree(const std::string& filename) const
{
    std::ofstream file(filename);
    file << "[\n";
    for (size_t i = 0; i < stockTree.size(); i++){
        file << "  [";
        for (size_t j = 0; j < stockTree[i].size(); j++){
            file << stockTree[i][j];
            if (j + 1 != stockTree[i].size())
                file << ", ";
        }
        file << "]";
        if (i + 1 != stockTree.size())
            file << ",";
        file << "\n";
    }
    file << "]";
}
void Binomial_Tree::exportoptionsTree(const std::string& filename) const
{
    std::ofstream file(filename);
    file << "[\n";
    for (size_t i = 0; i <optionsTree.size(); i++){
        file << "  [";
        for (size_t j = 0; j < optionsTree[i].size(); j++){
            file <<optionsTree[i][j];
            if (j + 1 != optionsTree[i].size())
                file << ", ";
        }
        file << "]";
        if (i + 1 != optionsTree.size())
            file << ",";
        file << "\n";
    }
    file << "]";
}

Binomial_Tree::Binomial_Tree(double S0,double sigma,double r,double T,int N){
    this->S0 = S0;
    this->sigma = sigma;
    this->r = r;
    this->T = T;
    this->N = N;

    dt = T/N;
    u = std::exp(sigma* std::sqrt(dt));
    d = 1.0/u;
    p = (std::exp(r*dt)-d)/(u-d);
    if(p<0 || p>1){
        std::cerr<<"Invalid Risk- Neutral Probability (duhh). "<<'\n';
    }
}

void Binomial_Tree::buildStockTree(){
    stockTree.clear();
    for (int i = 0; i <= N; i++){
        std::vector<double> level;
        for (int j = 0; j <= i; j++){
            double price = S0 * std::pow(u,j)*std::pow(d,i-j);
            level.push_back(price);
        }
        stockTree.push_back(level);
    }
}
void Binomial_Tree::buildOptionTree(const Option& option){
    optionsTree.clear();
    std::vector<double> lastOptionLevel;
    for(double stockPrice:stockTree.back()){
        if(option.is_Call){
            lastOptionLevel.push_back(longcall(stockPrice, option.strike));
        }
        else{
            lastOptionLevel.push_back(longput(stockPrice,option.strike));
        }
    }
    std::vector<double> currentLevel= lastOptionLevel;
    optionsTree.push_back(lastOptionLevel);
    while(currentLevel.size()>1){
        std::vector<double> nextLevel;
        for(int j =0; j< currentLevel.size()-1; j++){
            double value = std::exp(-r*dt)*(p*currentLevel[j+1]+(1-p)*currentLevel[j]);
            nextLevel.push_back(value);
        }
        optionsTree.push_back(nextLevel);
        currentLevel = nextLevel;
    }
}

void Binomial_Tree::printStockTree(){
    for(const auto& level:stockTree){
        for(double price:level){
            std::cout<<price<<" ";
        }
        std::cout<<"\n";
    }
}

void Binomial_Tree::printOptionTree(){
    for(const auto& level:optionsTree){
        for(double value:level){
            std::cout<<value<<" ";
        }std::cout<<'\n';
    }
}
double Binomial_Tree::getOptionsPrice()const{
    return optionsTree.back()[0];
}