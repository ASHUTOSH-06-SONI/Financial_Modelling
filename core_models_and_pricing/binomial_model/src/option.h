#ifndef OPTION_H
#define OPTION_H

class Option{
    public:
        double spot;
        double strike; 
        double sigma; 
        double r;
        double maturity;
        bool is_Call;
};

#endif