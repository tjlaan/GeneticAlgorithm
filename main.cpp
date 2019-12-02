#include <iostream>
#include <random>
#include "Population.hpp"

vector<City*> generate_master() {
    vector<City*> master;
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> intDistribution(0, 1000);

    for(int i = 0;i < 32;i++) {
        master.push_back(new City("City " + to_string(i), intDistribution(generator), intDistribution(generator)));
    }

    return master;
}

int main() {
    auto master = generate_master();
    Population* pop = new Population(master);

    double base_fitness = pop -> get_best_fitness();
    double best_fitness = base_fitness;
    double best_distance = pop -> get_best_distance();
    int iterations = 0;

    while(best_fitness/base_fitness < 1.3 && iterations < 1001) {
        pop -> iterate();

        iterations++;

        cout << "Iteration " << iterations << " : Distance " << pop -> get_best_distance() << endl;

        if(best_fitness < pop -> get_best_fitness()) {
            best_fitness = pop -> get_best_fitness();
            best_distance = pop -> get_best_distance();
            cout << "Improvement made. " << endl;
        } else {
            cout << "No improvement. " << endl;
        }

        cout << "Best distance so far: " << best_distance << endl;
        cout << "Improvement over base so far: " << best_fitness/base_fitness << " times as fit." << endl << endl;
    }

    cout << "Number of iterations: " << iterations;


    return 0;
}