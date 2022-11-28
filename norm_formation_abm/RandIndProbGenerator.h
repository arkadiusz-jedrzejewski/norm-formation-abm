#pragma once
#include <random>
#include "custom_types.h"

class RandIndProbGenerator
{
private:
	double mean;
protected:
	RNG& generator;
public:
	RandIndProbGenerator(RNG& generator, double mean);
	virtual double generate_ind_prob() = 0;
	double get_mean() const;
};

