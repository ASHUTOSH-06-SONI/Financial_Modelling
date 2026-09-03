// variance equation- V_(t+delta_T) = V_t + kappa*(theta- Vt)* Delta_T + xi*sqrt(V_t*delta_T)*Z
#ifndef CIR_PROCESS_H
#define CIR_PROCESS_H
#include "heston_model.h"
double cir(double V, Heston_params& params, double dt,double Z);
#endif
