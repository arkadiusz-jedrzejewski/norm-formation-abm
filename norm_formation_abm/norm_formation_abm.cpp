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
#include "MovingUniform.h"

int main(int argc, char** argv)
{
    int seed = atoi(argv[2]);
    std::mt19937_64 generator(seed);

    bool is_annealed = atoi(argv[5]);
    
    double p = atof(argv[12]);
    //double eps = atof(argv[10]);
    BernoulliDistribution distribution(generator, p);
    //MovingUniform distribution(generator, a, eps);

    double q = atof(argv[8]);
    ResponseFunction* conformity_function;
    bool is_symmetric = atoi(argv[6]);
    if (is_symmetric)
    {
        conformity_function = new SymmetricPower(q);
    }
    else
    {
        conformity_function = new Power(q);
    }
   
    double x0 = atof(argv[9]);
    double k = atof(argv[10]);
    double m = atof(argv[11]);
    Logistic nonconformity_function(x0, k, m);
    
    int system_size = atoi(argv[3]);
    int init_opinions = atoi(argv[7]);
    SocialSystem social_system(system_size,
        init_opinions,
        is_annealed,
        distribution,
        *conformity_function,
        nonconformity_function,
        generator);
    
    int time_horizon = atoi(argv[4]);
    std::string file_name = argv[1];
    /*std::cout << "p:\t" << p << std::endl;
    std::cout << "q:\t" << q << std::endl;
    std::cout << "k:\t" << k << std::endl;
    std::cout << "x0:\t" << x0 << std::endl;
    std::cout << "m:\t" << m << std::endl;
    std::cout << "is_symmetric:\t" << is_symmetric << std::endl;
    std::cout << "is_annealed:\t" << is_annealed << std::endl;
    std::cout << "seed:\t" << seed << std::endl;
    std::cout << "time_horizon:\t" << time_horizon << std::endl;
    std::cout << "system_size:\t" << system_size << std::endl;*/
    social_system.simulation(time_horizon, file_name);

    delete conformity_function;
}