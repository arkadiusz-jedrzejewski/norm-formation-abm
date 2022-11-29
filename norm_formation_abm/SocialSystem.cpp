#include "SocialSystem.h"
#include <iostream>

SocialSystem::SocialSystem(int size, int init_opinion, RandIndProbGenerator& distribution)
	:size(size)
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

void SocialSystem::print_agents()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << agents[i]->get_index() << "\t" 
			<< agents[i]->get_opinion() << "\t" 
			<< agents[i]->get_ind_prob() << std::endl;
	}
}
