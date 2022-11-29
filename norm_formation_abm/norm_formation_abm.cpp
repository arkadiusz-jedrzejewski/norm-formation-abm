﻿// norm_formation_abm.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <random>
#include "Agent.h"
#include "BernoulliDistribution.h"
#include "Uniform.h"
#include "SocialSystem.h"

int main()
{
    std::cout << "Hello World!\n";
    std::mt19937_64 generator(10);
    Uniform distribution(generator, 0.2);
   
    SocialSystem test_system(15, 1, distribution, generator);
    test_system.print_agents();
    test_system.single_update();
    test_system.single_update();
    test_system.single_update();
    //Agent& agent = test_system.choose_agent();
    //test_system.choose_agent();
    //test_system.choose_agent();
    std::cout << "///////////////////" << std::endl;
    //agent.change_opinion();
    //agent.change_ind_prob();
    test_system.print_agents();
    test_system.print_one_group_size();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln