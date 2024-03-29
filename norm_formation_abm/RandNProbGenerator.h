#pragma once
#include <random>
#include "custom_types.h"

class RandNProbGenerator
{
private:
	double mean;
protected:
	RNG& generator;
public:
	RandNProbGenerator(RNG& generator, double mean);
	virtual double generate() = 0;
	double get_mean() const;
};

