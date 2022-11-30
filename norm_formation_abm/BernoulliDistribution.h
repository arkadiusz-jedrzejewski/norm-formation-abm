#pragma once
#include <random>
#include "RandNProbGenerator.h"

class BernoulliDistribution :
    public RandNProbGenerator
{
private:
    double p;
    std::bernoulli_distribution distribution;
public:
    BernoulliDistribution(RNG& generator, double p);
    virtual double generate();
};

