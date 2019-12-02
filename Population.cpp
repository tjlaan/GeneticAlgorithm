//
// Created by tjlaa on 2019-12-01.
//

#include <iostream>
#include "Population.hpp"

Population::Population(vector<City*> c) {
    for(int i = 0;i < 32;i++) {
        tours.push_back(new Tour(c));
    }

    unsigned int bestTour = 0;
    for(unsigned int i = 1;i < tours.size();i++) {
        if(tours[bestTour] -> get_fitness() < tours[i] -> get_fitness()) {
            bestTour = i;
        }
    }

    swap(tours[0],tours[bestTour]);
}

Tour* Population::select_parent() {
    vector<Tour*> pool;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> intDistribution(0, 31);

    while(pool.size() < 5) {
        int index = intDistribution(generator);
        bool found = false;
        for(unsigned int i = 0;i < pool.size();i++) {
            if(pool[i] == tours[index]) {
                found = true;
            }
        }
        if(!found) {
            pool.push_back(tours[index]);
        }
    }

    Tour* best = pool[0];
    for(int i = 1;i < 5;i++) {
        if(best -> get_fitness() < pool[i] -> get_fitness()) {
            best = pool[i];
        }
    }

    return best;
}

void Population::iterate() {
    Tour parent1 = *select_parent();
    Tour parent2 = *select_parent();

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> intDistribution(0, 100);

    for(unsigned int i = 1;i < tours.size();i++) {
        Tour* newTour = new Tour(&parent1, &parent2);
        delete tours[i];
        if(intDistribution(generator) < 25) {
            newTour -> mutate();
        }
        tours[i] = newTour;
    }

    unsigned int bestTour = 0;
    for(unsigned int i = 1;i < tours.size();i++) {
        if(tours[bestTour] -> get_fitness() < tours[i] -> get_fitness()) {
            bestTour = i;
        }
    }

    swap(tours[0],tours[bestTour]);
}

ostream& operator<<(ostream& out, const Population& obj) {
    for(Tour* t : obj.tours) {
        out << *t << endl;
    }

    return out;
}