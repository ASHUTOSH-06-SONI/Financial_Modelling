#include"utils.h"
#include<algorithm>
#include<iostream>
double toDouble(std::string s){
    s.erase(std::remove(s.begin(),s.end(),','),s.end());
    return std::stod(s);
}
/*
int main(){
    std::cout << toDouble("21,650.00") << '\n';
}*/