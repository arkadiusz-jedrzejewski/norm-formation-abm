#include "VoterIndependence.h"

VoterIndependence::VoterIndependence(double f)
	: f(f)
{
}

void VoterIndependence::conformity(Agent& agent, double conc, RNG& generator)
{
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	int opinion = agent.get_opinion();
	double rand = unif_real_distribution(generator);

	if (rand < f)
	{
		agent.change_opinion();
	}
}
