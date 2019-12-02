//
// Created by tjlaa on 2019-12-01.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include <random>
#include "City.hpp"

using namespace std;

class Tour {
private:
    double fitness;
    vector<City*> cities;
    double get_city_distance(City*, City*);
    double get_tour_distance();
    void shuffle_cities();
public:
    Tour(vector<City*> cities) : cities(cities) {
        shuffle_cities();
        fitness = 1/get_tour_distance() * 10000;
    }
    double get_fitness() { return fitness; };
    friend ostream& operator << (ostream&, const Tour&);
};


#endif //GENETICALGORITHM_TOUR_HPP
