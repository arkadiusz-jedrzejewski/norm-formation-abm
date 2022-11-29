#pragma once
#include "Agent.h"
class SocialSystem
{
private:
	Agent** agents;
	int size;

public:
	SocialSystem(int size, int init_opinion, RandIndProbGenerator& distribution);
	~SocialSystem();

	void print_agents() const;
};

