#pragma once
#include "ResponseFunction.h"
class Logistic :
    public ResponseFunction
{
private:
    double x0;
    double k;
    double m;
public:
    Logistic(double x0, double k, double m);
    virtual void run(Agent& agent, double conc, RNG& generator);
};

