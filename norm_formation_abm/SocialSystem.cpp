#include "SocialSystem.h"

SocialSystem::SocialSystem(int size, int init_opinion, RandIndProbGenerator& distribution)
{
	agents = new Agent * [size];
	for (int i = 0; i < size; i++)
	{
		agents[i] = new Agent(i, init_opinion, distribution);
	}
}

SocialSystem::~SocialSystem()
{
	for (int i = 0; i < size; i++)
	{
		delete agents[i];
	}
	delete[] agents;
}
