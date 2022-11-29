#include "SocialSystem.h"
#include <iostream>

SocialSystem::SocialSystem(int size, int init_opinion, RandIndProbGenerator& distribution, RNG& generator)
	:size(size), generator(generator)
{
	agents = new Agent * [size];
	for (int i = 0; i < size; i++)
	{
		agents[i] = new Agent(i, init_opinion, distribution);
	}
	unif_int_distribution = std::uniform_int_distribution<int>(0, size - 1);
}

SocialSystem::~SocialSystem()
{
	for (int i = 0; i < size; i++)
	{
		delete agents[i];
	}
	delete[] agents;
}

void SocialSystem::print_agents() const
{
	std::cout << "index\topinion\tind_prob" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << agents[i]->get_index() << "\t" 
			<< agents[i]->get_opinion() << "\t" 
			<< agents[i]->get_ind_prob() << std::endl;
	}
}

Agent& SocialSystem::choose_agent()
{
	int random_number = unif_int_distribution(generator);
	std::cout << "number:\t" << random_number << std::endl;
	return *agents[random_number];
}
