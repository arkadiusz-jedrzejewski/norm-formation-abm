#include "MovingUniform.h"

MovingUniform::MovingUniform(RNG& generator, double a, double eps)
	: RandNProbGenerator(generator, a), a(a), eps(eps)
{
	distribution = std::uniform_real_distribution<double>(a - eps, a + eps);
}

double MovingUniform::generate()
{
	return distribution(generator);
}
