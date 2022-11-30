#include "Agent.h"
#include <iostream>

Agent::Agent(int index, int opinion, RandIndProbGenerator& distribution, ResponseFunction& conformity_function, ResponseFunction& nonconformity_function)
	: index(index), opinion(opinion), distribution(distribution), conformity_function(conformity_function), nonconformity_function(nonconformity_function)
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
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	double rand = unif_real_distribution(generator);
	//std::cout << "rand:\t" << rand << std::endl;
	if (rand < ind_prob)
	{
		//independence, individual learinig
		nonconformity_function.conformity(*this, conc, generator);
	}
	else 
	{
		//conformity, social learining
		conformity_function.conformity(*this, conc, generator);
	}
}


