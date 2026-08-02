#include<iostream>
#include"payoff.h"
int main(){
    double S_t = 120;
    double k = 100;
    std::cout<<"Long Call : "<<longcall(S_t,k)<<std::endl;   
    std::cout<<"Long Put : "<<longput(S_t,k)<<std::endl;
    std::cout<<"Short Call : "<<shortcall(S_t,k)<<std::endl;
    std::cout<<"Short Put : "<<shortput(S_t,k)<<std::endl;
    return 0;
}