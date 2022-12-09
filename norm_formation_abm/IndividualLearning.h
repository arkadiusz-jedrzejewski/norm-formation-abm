#pragma once
#include "ResponseFunction.h"
class IndividualLearning :
    public ResponseFunction
{
private:
    double f;
public:
    IndividualLearning(double f);
    virtual void run(Agent& agent, double conc, RNG& generator);
};

