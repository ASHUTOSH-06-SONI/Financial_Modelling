#include"option.h"
#include<iostream>
int main(){
    Option opt;
    opt.spot = 120;
    opt.strike = 100;
    opt.sigma = 0.2;
    opt.r= 0.05;
    opt.maturity= 30.0/365.0;
    opt.is_Call= true;
    std::cout<<opt.spot<<std::endl;
}