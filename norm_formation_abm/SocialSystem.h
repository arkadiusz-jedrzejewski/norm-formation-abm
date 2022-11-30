#pragma once
#include "Agent.h"
class SocialSystem
{
private:
	RNG& generator;
	Agent** agents;
	std::uniform_int_distribution<int> unif_int_distribution;
	int size;
	int one_group_size; //number of agents with opinion 1

public:
	SocialSystem(int size, int init_opinion, RandIndProbGenerator& distribution, RNG& generator);
	~SocialSystem();

	void print_agents() const;
	Agent& choose_agent();
	void single_update();
	void single_mcs();
	void simulation(int time_horizon, std::string file_name);
	void print_one_group_size() const;

	double get_conc() const;
};

