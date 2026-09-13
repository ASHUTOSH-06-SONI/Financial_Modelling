// Generate independent standard normals- Z1,Z2~ N(0,1) then turn them into correlated shocks
#ifndef BROWNIAN_H
#define BROWNIAN_H
double standard_normal();
void correlated_normals(double rho, double& Zs, double& Zv);
#endif