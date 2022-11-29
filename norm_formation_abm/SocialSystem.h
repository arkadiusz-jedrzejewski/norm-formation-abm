#pragma once
#include "Agent.h"
class SocialSystem
{
private:
	RNG& generator;
	Agent** agents;
	int size;

public:
	SocialSystem(int size, int init_opinion, RandIndProbGenerator& distribution, RNG& generator);
	~SocialSystem();

	void print_agents() const;
	void choose_agent();
};

