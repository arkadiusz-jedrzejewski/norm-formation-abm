#pragma once
#include <vector>
#include "RandNProbGenerator.h"
#include "ResponseFunction.h"
class ResponseFunction;
class Agent
{
private:
	int index;
	int opinion;
	bool is_annealed;
	double n_prob;	//	nonconformity proability : with probability n_prob -> nonconformity, otherwise (with probability 1 - n_prob) -> conformity
	RandNProbGenerator& distribution;
	ResponseFunction& conformity_function;
	ResponseFunction& nonconformity_function;

public:
	Agent(int index,
		int opinion,
		bool is_annealed,
		RandNProbGenerator& distribution, 
		ResponseFunction& conformity_function, 
		ResponseFunction& nonconformity_function);

	int get_index() const;
	int get_opinion() const;
	double get_n_prob() const;

	void change_n_prob();

	void change_opinion();
	void set_opinion(int new_opinion);
	void reconsider_opinion(double conc, RNG& generator);
	
};

