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
    Population(vector<City*> c);
    friend ostream& operator << (ostream&, const Population&);
    Tour* select_parent();
    double get_best_fitness() { return tours[0] -> get_fitness(); }
    double get_best_distance() { return tours[0] -> get_tour_distance(); }
    void iterate();
};


#endif //GENETICALGORITHM_POPULATION_HPP
