#include "BernoulliDistribution.h"

BernoulliDistribution::BernoulliDistribution(RNG& generator, double p)
	: RandNProbGenerator(generator, p), p(p)
{
	distribution = std::bernoulli_distribution(p);
}

double BernoulliDistribution::generate()
{
	return distribution(generator);
}


