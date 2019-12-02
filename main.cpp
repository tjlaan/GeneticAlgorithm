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
    double base_distance = pop -> get_best_distance();
    vector<City*> base_route = pop -> get_best_route();
    double best_fitness = base_fitness;
    double best_distance = pop -> get_best_distance();
    vector<City*> best_route = pop -> get_best_route();
    int iterations = 0;

    while(best_fitness/base_fitness < 1.3 && iterations < 1000) {
        pop -> iterate();

        iterations++;

        cout << "Iteration " << iterations << " : Distance " << pop -> get_best_distance() << endl;

        cout << "Best distance so far: " << best_distance << endl;

        if(best_fitness < pop -> get_best_fitness()) {
            best_fitness = pop -> get_best_fitness();
            best_distance = pop -> get_best_distance();
            best_route = pop -> get_best_route();
            cout << "Improvement made. " << endl;
        } else {
            cout << "No improvement. " << endl;
        }

        cout << "Improvement over base so far: " << best_fitness/base_fitness << " times as fit." << endl << endl;
    }

    cout << endl << "Number of iterations: " << iterations << endl;
    cout << "Base Distance: " << base_distance << endl;
    cout << "Best Distance: " << best_distance << endl << endl;
    cout << "Base Route:" << endl;
    for(City* c : base_route) {
        cout << *c << endl;
    }
    cout << *base_route[0] << endl << endl;
    cout << "Best Route:" << endl;
    for(City* c : best_route) {
        cout << *c << endl;
    }
    cout << *best_route[0];

    return 0;
}