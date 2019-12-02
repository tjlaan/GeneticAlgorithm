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
};


#endif //GENETICALGORITHM_POPULATION_HPP
