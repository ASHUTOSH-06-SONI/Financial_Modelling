#include<iostream>
#include"cir_process.h"
#include<cmath>
#include<algorithm>
double cir(double V,const Heston_params& params, double dt,double Z){
    double V_pos = std::max(V,0.0);
    return V+params.kappa*(params.theta-V_pos)*dt+params.xi*std::sqrt(V_pos*dt)*Z;
}