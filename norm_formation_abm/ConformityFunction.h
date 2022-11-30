#pragma once
#include "Agent.h"
class Agent;
class ConformityFunction
{
public:
	virtual void conformity(Agent& agent, double conc, RNG& generator) = 0;
};

