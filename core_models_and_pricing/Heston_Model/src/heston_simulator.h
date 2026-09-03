#ifndef HESTON_SIMULATOR_H
#define HESTON_SIMULATOR_H
#include<vector>
#include"heston_model.h"
struct HestonPath{
    std::vector<double> spot;
    std::vector<double> variance;
};
HestonPath simulate_path(const Heston_params& params, double T, int steps);
#endif