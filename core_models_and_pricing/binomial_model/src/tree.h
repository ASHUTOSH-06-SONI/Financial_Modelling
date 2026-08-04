#ifndef TREE_H
#define TREE_H
#include <vector>
#include"payoff.h"
#include"option.h"

class Binomial_Tree{
    private:
        double S0;
        double sigma;
        double r;
        double T;
        int N;
        double dt;
        double u;
        double d;
        double p;
        std::vector<std::vector<double>> stockTree;
        std::vector<std::vector<double>> optionsTree;

    public:
        Binomial_Tree(double S0, double sigma, double r, double T, int N);
        void buildStockTree();
        void printStockTree();
        void buildOptionTree(const Option& option);
        void printOptionTree();
        double getOptionsPrice() const;
        void exportStockTree(const std::string& filename)const;
        void exportoptionsTree(const std::string& filename)const;
};
#endif