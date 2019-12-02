//
// Created by tjlaa on 2019-12-01.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include "Tour.hpp"

class Population {
private:
    vector<Tour*> tours;
public:
    Population() = default;
    int get_tour_distance();
};


#endif //GENETICALGORITHM_POPULATION_HPP
