//
// Created by tjlaa on 2019-12-01.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include "City.hpp"

using namespace std;

class Tour {
private:
    double fitness;
    vector<City*> cities;
    double get_city_distance(City*, City*);
public:
    Tour(vector<City*> cities) : cities(cities) {}
    double get_tour_distance();
};


#endif //GENETICALGORITHM_TOUR_HPP
