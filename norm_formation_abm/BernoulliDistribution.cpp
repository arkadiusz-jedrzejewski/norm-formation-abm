#include "BernoulliDistribution.h"

BernoulliDistribution::BernoulliDistribution(RNG& generator, double p)
	: RandNProbGenerator(generator, p), p(p)
{
	distribution = std::bernoulli_distribution(p);
}

double BernoulliDistribution::generate_ind_prob()
{
	return distribution(generator);
}


