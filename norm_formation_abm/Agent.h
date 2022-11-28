#pragma once
#include <vector>
#include "RandIndProbGenerator.h"

class Agent
{
private:
	int index;
	int opinion;
	double ind_prob;	//independence probability
	RandIndProbGenerator& distribution;

public:
	Agent(int index, int opinion, RandIndProbGenerator& distribution);

	int get_index() const;
	int get_opinion() const;
	double get_ind_prob() const;

	void change_ind_prob();

	void change_opinion();
	
};

