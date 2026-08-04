#include "tree.h"
#include <cmath>
#include<iostream>
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
}

void Binomial_Tree::buildStockTree(){
    for (int i = 0; i <= N; i++){
        std::vector<double> level;
        for (int j = 0; j <= i; j++){
            double price = S0 * std::pow(u,j)*std::pow(d,i-j);
            level.push_back(price);
        }
        stockTree.push_back(level);
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