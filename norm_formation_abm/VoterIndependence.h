#pragma once
#include "ConformityFunction.h"
class VoterIndependence :
    public ConformityFunction
{
private:
    double f;
public:
    VoterIndependence(double f);
    virtual void conformity(Agent& agent, double conc, RNG& generator);
};

