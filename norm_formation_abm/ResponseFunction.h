#pragma once
#include "Agent.h"
class Agent;
class ResponseFunction
{
public:
	virtual void run(Agent& agent, double conc, RNG& generator) = 0;
};

