// norm_formation_abm.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <random>
#include "Agent.h"
#include "BernoulliDistribution.h"
#include "Uniform.h"
#include "SocialSystem.h"
#include "Power.h"
#include "SymmetricPower.h"
#include "Logistic.h"
#include "VoterIndependence.h"
#include "IndividualLearning.h"

int main(int argc, char** argv)
{
    int seed = atoi(argv[1]);
    std::mt19937_64 generator(seed);

    bool is_annealed = atoi(argv[2]);
    
    double p = atof(argv[3]);
    BernoulliDistribution distribution(generator, p);
    
    double q = atof(argv[4]);
    Power conformity_function(q);
    
    double f = atof(argv[5]);
    IndividualLearning nonconformity_function(f);
    
    int system_size = atoi(argv[6]);
    int init_opinions = atoi(argv[7]);
    SocialSystem social_system(system_size,
        init_opinions,
        is_annealed,
        distribution,
        conformity_function,
        nonconformity_function,
        generator);
    
    int time_horizon = atoi(argv[8]);
    std::string file_name = argv[9];
    social_system.simulation(time_horizon, file_name);
}