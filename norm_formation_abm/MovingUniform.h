#pragma once
#include "RandNProbGenerator.h"
class MovingUniform :
    public RandNProbGenerator
{
private:
    //  Uniform distribution: U(a-eps, a+eps)
    double a;   //  center of uniform distribution
    double eps; //  half of width of uniform distribution
    std::uniform_real_distribution<double> distribution;
public:
    MovingUniform(RNG& generator, double a, double eps);
    virtual double generate();
    
};

