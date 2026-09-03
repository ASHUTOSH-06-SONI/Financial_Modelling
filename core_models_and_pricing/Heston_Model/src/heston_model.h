#ifndef HESTON_MODEL_H
#define HESTON_MODEL_H
struct Heston_params{
    double S0; // initial price
    double V0; // initial variance
    double r;  // risk free rate of interest
    double kappa; // speed of mean reversion
    double theta; // variance in long run
    double xi;    // volatility of variance
    double rho;   // correlation
};
#endif