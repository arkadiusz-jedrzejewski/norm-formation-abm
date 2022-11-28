#pragma once
#include "RandIndProbGenerator.h"
class Uniform :
    public RandIndProbGenerator
{
private:
    double a; //distribution support: (0, a)
    std::uniform_real_distribution<double> distribution;
public:
    Uniform(RNG& generator, double a);
    virtual double generate_ind_prob();
};

