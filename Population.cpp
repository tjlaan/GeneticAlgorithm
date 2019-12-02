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

    base_fitness = tours[0] -> get_fitness();
}

Tour* Population::select_parent() {
    vector<Tour*> pool;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> intDistribution(1, 31);

    while(pool.size() < 5) {
        int index = intDistribution(generator);
        cout << index << " ";
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

ostream& operator<<(ostream& out, const Population& obj) {
    for(Tour* t : obj.tours) {
        out << *t << endl;
    }

    return out;
}