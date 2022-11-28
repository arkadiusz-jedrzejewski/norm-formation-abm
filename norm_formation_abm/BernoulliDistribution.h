#pragma once
#include <random>
#include "RandIndProbGenerator.h"

class BernoulliDistribution :
    public RandIndProbGenerator
{
private:
    double p;
    std::bernoulli_distribution distribution;
public:
    BernoulliDistribution(RNG& generator, double p);
    virtual double generate_ind_prob();
};

