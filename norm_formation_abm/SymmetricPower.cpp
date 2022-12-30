#include "SymmetricPower.h"

SymmetricPower::SymmetricPower(double q)
	: q(q)
{
}

void SymmetricPower::run(Agent& agent, double conc, RNG& generator)
{
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	int opinion = agent.get_opinion();
	double rand = unif_real_distribution(generator);

	if (opinion == 1)
	{
		if (conc > 0.5)
		{
			if (rand < std::pow(2 * (1 - conc), q) / 2.0)
			{
				agent.set_opinion(-1);
			}
		}
		else
		{
			// conc >= 0.5
			if (rand < 1 - std::pow(2 * conc, q) / 2.0)
			{
				agent.set_opinion(-1);
			}
		}
	}
	else
	{
		// opinion = -1
		if (conc < 0.5)
		{
			if (rand < std::pow(2 * conc, q) / 2.0)
			{
				agent.set_opinion(1);
			}
		}
		else
		{
			// conc >= 0.5
			if (rand < 1 - std::pow(2 * (1 - conc), q) / 2.0)
			{
				agent.set_opinion(1);
			}
		}
	}
}
