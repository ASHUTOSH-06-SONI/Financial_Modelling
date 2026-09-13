#include<iostream>
#include<vector>
#include"heston_model.h"
#include"heston_simulator.h"

int main(){
    Heston_params params;
    params.S0 = 100;
    params.V0 = 0.04;
    params.r = 0.05;
    params.kappa = 2.0;
    params.theta = 0.04;
    params.xi = 0.3;
    params.rho = -0.7;
    double T = 1.0;
    int steps = 100;
    HestonPath path = simulate_path(params,T,steps);
    std::cout<<"Initial S : "<< path.spot[0]<<std::endl;
    std::cout<<"Final S :"<<path.spot[steps]<<std::endl;
    std::cout<<"Initial V :"<<path.variance[0]<<std::endl;
    std::cout<<"Final V :"<<path.variance[steps]<<std::endl;
    for(int i = 0; i<steps; i+= 10){
        std::cout<<"t = "<<i*T/steps<<"| S = "<<path.spot[i]<<" | V = "<<path.variance[i]<<std::endl;
    }
    std::vector<double> variance_sum(steps+1,0.0);
    std::vector<double> variance_avg(steps+1);
    int paths = 10000;
    for(int i = 0; i<paths; i++){
        HestonPath path = simulate_path(params,T,steps);
        for(int j = 0; j<= steps; j++){
            variance_sum[j]+=path.variance[j];
        }
    }
    for(int i = 0; i<=steps; i++){
        variance_avg[i] =variance_sum[i]/paths;
    }
    for(auto i : variance_avg){
        std::cout<<i<<std::endl;
    }
}