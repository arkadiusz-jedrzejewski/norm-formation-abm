#pragma once
#include "ResponseFunction.h"
class VoterIndependence :
    public ResponseFunction
{
private:
    double f;
public:
    VoterIndependence(double f);
    virtual void conformity(Agent& agent, double conc, RNG& generator);
};

