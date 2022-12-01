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

int main()
{
    int seed = 10;
    std::mt19937_64 generator(seed);

    double p = 0.2;
    BernoulliDistribution distribution(generator, p);

    double q = 3;
    Power conformity_function(q);

    double f = 0.5;
    VoterIndependence nonconformity_function(f);

    int system_size = 10000;
    int init_opinions = 1;
    SocialSystem social_system(system_size, 
        init_opinions, 
        distribution, 
        conformity_function, 
        nonconformity_function, 
        generator);
    
    int time_horizon = 200;
    std::string file_name = "name.txt";
    social_system.simulation(time_horizon, file_name);
}