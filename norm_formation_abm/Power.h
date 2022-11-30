#pragma once
#include "ResponseFunction.h"
class Power :
    public ResponseFunction
{
private:
    double q; // exponent : f(x) = x ^ q
public:
    Power(double q);
    virtual void conformity(Agent& agent, double conc, RNG& generator);
};

