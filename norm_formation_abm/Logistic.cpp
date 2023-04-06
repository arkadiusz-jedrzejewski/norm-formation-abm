#include "Logistic.h"

Logistic::Logistic(double x0, double k, double m)
	: x0(x0), k(k), m(m)
{
}

void Logistic::run(Agent& agent, double conc, RNG& generator)
{
	std::uniform_real_distribution<double> unif_real_distribution(0, 1);
	int opinion = agent.get_opinion();
	double rand = unif_real_distribution(generator);

	if (rand < 2.0 * m / (1 + std::exp(-k * (conc - x0))))
	{
		agent.set_opinion(1);
	}
	else
	{
		agent.set_opinion(-1);
	}
}
