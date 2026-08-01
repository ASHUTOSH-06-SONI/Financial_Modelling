//#include<Python.h>
#include<iostream>
//#include <boost/property_tree/ptree.hpp>
#include<string>
#include<sstream>
#include<fstream>
#include<math.h>
#include"gbm.h"
#include<time.h>
#include<vector>
//#include"matplotlibcpp.h"
#define ll long long 
#include <random>

std::mt19937 rng(time(nullptr));
std::uniform_real_distribution<> dist(0.0, 1.0);
double GBMSimulator::uniform(){
    // now i'll replace the standard number gen with Mersenne Twister
    static std::mt19937 rng(time(nullptr));
    static std::uniform_real_distribution<> dist(0.0, 1.0);
    return dist(rng);
}
double GBMSimulator::gaussian(){
    // box muller transform, basically used for converting 2 uniform nums
    // into 1 gaussian random number N(0,1)
    // random angle + random radius = gaussian random number
    double u1 = uniform();  // this acts as random angle
    double u2 = uniform();  // this acts as random radius 
    return sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2);  // box muller formula
}
GBMSimulator::GBMSimulator(double init_price, double drift, double volatility, double time_horizon)
    : S0(init_price), mu(drift), sigma(volatility), T(time_horizon), current_state(time(nullptr)) {}

std::vector<std::vector<double>> GBMSimulator::simulate(int num_steps, int num_paths){
    std::vector<std::vector<double>> paths;
    for(int i =0; i<num_paths;i++){
        std::vector<double> path; 
        double price = S0;
        double dt = T/num_steps;
        for(int j =0; j<num_steps;j++){
            double Z = gaussian();
            price = price*exp((mu-0.5*sigma*sigma)*dt +sigma*sqrt(dt)*Z);
            path.push_back(price);
        }      
        paths.push_back(path);
    }
    return paths; 
}
int main(){
    double S0 = 308.91;
    double mu = 0.05;
    double sigma = 0.20;
    double T = 1.0;
    GBMSimulator gbmsim1(S0, mu, sigma, T);
    auto paths = gbmsim1.simulate(252,1000);
    std::ofstream outfile("gbm_output.csv");
    for(int j = 0;j<paths[0].size();j++){
        for(int i=0; i<paths.size();i++){
            outfile<<paths[i][j];
            if(i<paths.size()-1) outfile<<",";
        }outfile<<"\n";
    }
    outfile.close();
    for(int i =0; i<10; i++){ //This is one simulated path (first of 1000) over 10 time steps (out of 252).
        std::cout<<paths[0][i]<<std::endl;
    }
    return 0;
}