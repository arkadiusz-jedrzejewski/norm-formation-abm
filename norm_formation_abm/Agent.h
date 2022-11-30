#pragma once
#include <vector>
#include "RandIndProbGenerator.h"
#include "ConformityFunction.h"
class ConformityFunction;
class Agent
{
private:
	int index;
	int opinion;
	double ind_prob;	//independence probability
	RandIndProbGenerator& distribution;
	ConformityFunction& conformity_function;
	ConformityFunction& engagement_function;

public:
	Agent(int index, 
		int opinion, 
		RandIndProbGenerator& distribution, 
		ConformityFunction& conformity_function, 
		ConformityFunction& engagement_function);

	int get_index() const;
	int get_opinion() const;
	double get_ind_prob() const;

	void change_ind_prob();

	void change_opinion();
	void set_opinion(int new_opinion);
	void reconsider_opinion(double conc, RNG& generator);
	
};

