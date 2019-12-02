#include <iostream>
#include <random>
#include "Population.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<City*> generate_master() {
    vector<City*> master;
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> intDistribution(0, 1000);

    for(int i = 0;i < 32;i++) {
        master.push_back(new City(&"City " [ i], intDistribution(generator), intDistribution(generator)));
    }
}