#include "IndividualLearning.h"

IndividualLearning::IndividualLearning(double f)
	: f(f)
{
}

void IndividualLearning::run(Agent& agent, double conc, RNG& generator)
{
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	double rand = unif_real_distribution(generator);

	if (rand < f)
	{
		agent.set_opinion(1);
	}
	else
	{
		agent.set_opinion(-1);
	}
}
