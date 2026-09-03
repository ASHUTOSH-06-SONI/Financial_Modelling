#include"brownian.h"
#include<cmath>
#include<random>
double standard_normal(){
    static std::random_device rd;
    static std::mt19937 generator(rd());
    static std::normal_distribution<double> distribution(0.0,1.0);
    return distribution(generator);
}
void correlated_normals(double rho, double& Zs, double& Zv){
    double Z1 = standard_normal();
    double Z2 = standard_normal();
    Zs = Z1;
    Zv = rho * Z1+ std::sqrt(1.0 - rho * rho) * Z2;
}