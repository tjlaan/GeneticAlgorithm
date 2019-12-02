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
    cout << *pop;

    return 0;
}