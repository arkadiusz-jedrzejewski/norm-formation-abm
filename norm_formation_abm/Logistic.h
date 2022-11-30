#pragma once
#include "ResponseFunction.h"
class Logistic :
    public ResponseFunction
{
private:
    double x0;
    double k;
public:
    Logistic(double x0, double k);
    virtual void run(Agent& agent, double conc, RNG& generator);
};

