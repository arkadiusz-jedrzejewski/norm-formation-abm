#include "Agent.h"
#include <iostream>

Agent::Agent(int index, int opinion, RandIndProbGenerator& distribution)
	: index(index), opinion(opinion), distribution(distribution)
{
	ind_prob = distribution.generate_ind_prob();
}

int Agent::get_index() const
{
	return index;
}

int Agent::get_opinion() const
{
	return opinion;
}

double Agent::get_ind_prob() const
{
	return ind_prob;
}

void Agent::change_ind_prob()
{
	ind_prob = distribution.generate_ind_prob();
}

void Agent::change_opinion()
{
	// changes the agent's opinion to the opposit
	opinion *=-1;
}

void Agent::set_opinion(int new_opinion)
{
	opinion = new_opinion;
}

void Agent::reconsider_opinion(double conc, RNG& generator)
{
	//std::cout << "index:\t" << index << std::endl;	
	//std::cout << "conc:\t" << conc << std::endl;
	double q = 3;
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	double rand = unif_real_distribution(generator);
	//std::cout << "rand:\t" << rand << std::endl;
	if (rand < ind_prob)
	{
		//independence, individual learinig
		double rand2 = unif_real_distribution(generator);
		//std::cout << "rand2:\t" << rand2<< std::endl;
		if (rand2 < 0.5)
		{
			change_opinion();
		}
	}
	else 
	{
		//conformity, social learining
		double rand3 = unif_real_distribution(generator);
		if (rand3 < std::pow(conc, q))
		{
			set_opinion(1);
		}
		else if(rand3< std::pow(conc, q) + std::pow(1-conc, q))
		{
			set_opinion(-1);
		}
	}
}


