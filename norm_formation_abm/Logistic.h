#pragma once
#include "ConformityFunction.h"
class Logistic :
    public ConformityFunction
{
private:
    double x0;
    double k;
public:
    Logistic(double x0, double k);
    virtual void conformity(Agent& agent, double conc, RNG& generator);
};

