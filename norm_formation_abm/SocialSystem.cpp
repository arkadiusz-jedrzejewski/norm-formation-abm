#include "SocialSystem.h"
#include <iostream>
#include <fstream>

SocialSystem::SocialSystem(int size, int init_opinion, RandIndProbGenerator& distribution, RNG& generator)
	:size(size), generator(generator)
{
	agents = new Agent * [size];
	for (int i = 0; i < size; i++)
	{
		agents[i] = new Agent(i, init_opinion, distribution);
	}
	unif_int_distribution = std::uniform_int_distribution<int>(0, size - 1);

	if (init_opinion == 1)
	{
		one_group_size = size;
	}
	else
	{
		one_group_size = 0;
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
	//std::cout << "number:\t" << random_number << std::endl;
	return *agents[random_number];
}

void SocialSystem::single_update()
{
	Agent& chosen_agent = choose_agent();
	int init_opinion = chosen_agent.get_opinion();
	//chosen_agent.change_opinion(); // TODO: change_opinion() may return changed opinion -> more compact code
	double conc = (init_opinion == 1) ? (one_group_size - 1.0) / (size - 1.0) : one_group_size / (size - 1.0);
	chosen_agent.reconsider_opinion(conc, generator);
	one_group_size += (chosen_agent.get_opinion() - init_opinion) / 2;
}

void SocialSystem::single_mcs()
{
	//random sequential updating scheme
	for (int i = 0; i < size; i++)
	{
		single_update();
	}
	print_one_group_size();
}

void SocialSystem::simulation(int time_horizon)
{
	std::string file_name = "name.txt";
	std::fstream data_file(file_name, std::ios::out);

	data_file << get_conc() << std::endl;
	for (int i = 0; i < time_horizon; i++)
	{
		single_mcs();
		data_file << get_conc() << std::endl;	//	saving concentration after every MCS
	}

	data_file.flush();
	data_file.close();
}

void SocialSystem::print_one_group_size() const
{
	std::cout << "one_group_size:\t" << one_group_size / (double) size << std::endl;
}

double SocialSystem::get_conc() const
{
	return one_group_size / (double) size;
}
