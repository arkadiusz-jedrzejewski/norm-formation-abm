#include "Uniform.h"

Uniform::Uniform(RNG& generator, double a)
	: RandIndProbGenerator(generator, a/2), a(a)
{
	distribution = std::uniform_real_distribution<double>(0, a);
}

double Uniform::generate_ind_prob()
{
	return distribution(generator);
}
