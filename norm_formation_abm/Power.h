#pragma once
#include "ConformityFunction.h"
class Power :
    public ConformityFunction
{
private:
    double q; // exponent : f(x) = x ^ q
public:
    Power(double q);
    virtual void conformity(Agent& agent, double conc, RNG& generator);
};

