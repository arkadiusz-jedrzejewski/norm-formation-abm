#pragma once
#include <vector>
#include "RandIndProbGenerator.h"
#include "ResponseFunction.h"
class ResponseFunction;
class Agent
{
private:
	int index;
	int opinion;
	double n_prob;	//	nonconformity proability : with probability n_prob -> nonconformity, otherwise (with probability 1 - n_prob) -> conformity
	RandIndProbGenerator& distribution;
	ResponseFunction& conformity_function;
	ResponseFunction& nonconformity_function;

public:
	Agent(int index, 
		int opinion, 
		RandIndProbGenerator& distribution, 
		ResponseFunction& conformity_function, 
		ResponseFunction& nonconformity_function);

	int get_index() const;
	int get_opinion() const;
	double get_n_prob() const;

	void change_ind_prob();

	void change_opinion();
	void set_opinion(int new_opinion);
	void reconsider_opinion(double conc, RNG& generator);
	
};

