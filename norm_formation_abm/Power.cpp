#include "Power.h"

Power::Power(double q)
	: q(q)
{
}

void Power::conformity(Agent& agent, double conc, RNG& generator)
{
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	int opinion = agent.get_opinion();
	double rand = unif_real_distribution(generator);

	if (opinion == 1)
	{
		if (rand < std::pow(1 - conc, q))
		{
			agent.set_opinion(-1);
		}
	}
	else
	{
		// opinion = -1
		if (rand < std::pow(conc, q))
		{
			agent.set_opinion(1);
		}
	}
}
