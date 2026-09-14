#include "heston_simulator.h"
#include "brownian.h"
#include "cir_process.h"

#include <cmath>
#include <algorithm>

HestonPath simulate_path(const Heston_params& params,double T,int steps) {
    double dt = T / steps;
    HestonPath path;
    path.spot.resize(steps + 1);
    path.variance.resize(steps + 1);
    path.spot[0] = params.S0;
    path.variance[0] = params.V0;
    for (int i = 0; i < steps; i++) {
        double Zs,Zv;
        correlated_normals(params.rho, Zs, Zv);
        double V_next = cir(path.variance[i],params,dt,Zv);
        double V_current = std::max(path.variance[i], 0.0);
        path.spot[i + 1] = path.spot[i] * std::exp((params.r - 0.5 * V_current) * dt+ std::sqrt(V_current * dt)*Zs);
        path.variance[i + 1] = V_next;
    }
    return path;
}