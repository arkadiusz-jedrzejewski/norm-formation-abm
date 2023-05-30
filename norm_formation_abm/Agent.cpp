#include "Agent.h"
#include <iostream>

Agent::Agent(
	int index, 
	int opinion, 
	bool is_annealed,
	RandNProbGenerator& distribution, 
	ResponseFunction& conformity_function, 
	ResponseFunction& nonconformity_function)
	: 
	index(index), 
	opinion(opinion), 
	is_annealed(is_annealed),
	distribution(distribution), 
	conformity_function(conformity_function), 
	nonconformity_function(nonconformity_function)
{
	if (index < round(distribution.get_mean() * 10))
	{
		n_prob = 1;
	}
	else
	{
		n_prob = 0;
	}
	//n_prob = distribution.generate();
}

int Agent::get_index() const
{
	return index;
}

int Agent::get_opinion() const
{
	return opinion;
}

double Agent::get_n_prob() const
{
	return n_prob;
}

void Agent::change_n_prob()
{
	n_prob = distribution.generate();
}

void Agent::change_opinion()
{
	//	changes the agent's opinion to the opposit
	opinion *=-1;
}

void Agent::set_opinion(int new_opinion)
{
	opinion = new_opinion;
}

void Agent::reconsider_opinion(double conc, RNG& generator)
{
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	double rand = unif_real_distribution(generator);
	
	if (rand < n_prob)
	{
		//	nonconformity : with probability n_prob
		nonconformity_function.run(*this, conc, generator);
	}
	else 
	{
		//	conformity : with probability 1 - n_prob
		conformity_function.run(*this, conc, generator);
	}
	
	if (is_annealed)
	{
		//	if annealed mode is on, an agent draws level (probability p) of nonconfomirty each time from the given distibution
		//	if annealed mode is off -> quenched mode is on, and an agnet does not change its level (probability p) of nonconformity, which was initially drawn form the given distibution
		change_n_prob();
	}
}


