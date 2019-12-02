//
// Created by tjlaa on 2019-12-01.
//

#include <iostream>
#include "Population.hpp"

Population::Population(vector<City*> c) {
    for(int i = 0;i < 32;i++) {
        tours.push_back(new Tour(c));
    }

    Tour* bestTour = tours[0];
    for(unsigned int i = 1;i < tours.size();i++) {
        if(bestTour -> get_fitness() < tours[i] -> get_fitness()) {
            bestTour = tours[i];
        }
    }
}

ostream& operator<<(ostream& out, const Population& obj) {
    for(Tour* t : obj.tours) {
        out << *t << endl;
    }

    return out;
}