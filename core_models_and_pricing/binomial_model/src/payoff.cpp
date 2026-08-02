#include"payoff.h"
#include<algorithm>
double longcall(double S_t, double k){
    return std::max(S_t-k,0.0);
}
double longput(double S_t, double k){
    return std::max(k - S_t, 0.0);
}
double shortcall(double S_t, double k){
    return std::max(k-S_t,0.0);
}
double shortput(double S_t, double k){
    return -std::max(k-S_t,0.0);
}
