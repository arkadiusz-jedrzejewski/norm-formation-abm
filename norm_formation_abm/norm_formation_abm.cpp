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

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        int seed = atoi(argv[1]);
        std::mt19937_64 generator(seed);

        double p = atof(argv[2]);
        BernoulliDistribution distribution(generator, p);

        double q = atof(argv[3]);
        Power conformity_function(q);

        double f = atof(argv[4]);
        VoterIndependence nonconformity_function(f);

        int system_size = atoi(argv[5]);
        int init_opinions = atoi(argv[6]);
        SocialSystem social_system(system_size,
            init_opinions,
            distribution,
            conformity_function,
            nonconformity_function,
            generator);

        int time_horizon = atoi(argv[7]);
        std::string file_name = argv[8];
        social_system.simulation(time_horizon, file_name);
    }
}