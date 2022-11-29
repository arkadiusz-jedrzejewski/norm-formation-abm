#pragma once
#include "Agent.h"
class SocialSystem
{
private:
	RNG& generator;
	Agent** agents;
	std::uniform_int_distribution<int> unif_int_distribution;
	int size;

public:
	SocialSystem(int size, int init_opinion, RandIndProbGenerator& distribution, RNG& generator);
	~SocialSystem();

	void print_agents() const;
	void choose_agent();
};

