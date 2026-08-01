#include<vector>
class GBMSimulator{
    public:
        // market parameters
        GBMSimulator(double init_price, double drift, double volatility, double time_horizon);
        std::vector<std::vector<double>> simulate(int num_steps, int num_paths);
    private:
        double S0, mu, sigma, T;
        int current_state;
        double uniform();
        double gaussian();
};
