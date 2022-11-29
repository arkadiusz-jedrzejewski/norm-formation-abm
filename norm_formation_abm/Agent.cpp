#include "Agent.h"

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

void Agent::reconsider_opinion(double conc, RNG& generator)
{
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	double rand = unif_real_distribution(generator);
	if (rand < ind_prob)
	{
		//independence, individual learinig
		if (unif_real_distribution(generator) < 0.5)
		{
			change_opinion();
		}
	}
	else 
	{
		//conformity, social learining
		
	}
}


