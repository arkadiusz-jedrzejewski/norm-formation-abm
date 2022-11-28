#include "RandIndProbGenerator.h"

RandIndProbGenerator::RandIndProbGenerator(RNG& generator, double mean) 
	: generator(generator), mean(mean)
{
}

double RandIndProbGenerator::get_mean() const
{
	return mean;
}
