#include "RandNProbGenerator.h"

RandNProbGenerator::RandNProbGenerator(RNG& generator, double mean) 
	: generator(generator), mean(mean)
{
}

double RandNProbGenerator::get_mean() const
{
	return mean;
}
