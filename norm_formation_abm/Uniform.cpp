#include "Uniform.h"

Uniform::Uniform(RNG& generator, double a)
	: RandNProbGenerator(generator, a/2), a(a)
{
	distribution = std::uniform_real_distribution<double>(0, a);
}

double Uniform::generate()
{
	return distribution(generator);
}
