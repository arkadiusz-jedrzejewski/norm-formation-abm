#pragma once
#include "ResponseFunction.h"
class SymmetricPower :
    public ResponseFunction
{
private:
    double q; // exponent : f(x) = (0 <= x < 0.5) ? (2x)^q/2 : 1-(2(1-x))^q/2
public:
    SymmetricPower(double q);
    virtual void conformity(Agent& agent, double conc, RNG& generator);
};

