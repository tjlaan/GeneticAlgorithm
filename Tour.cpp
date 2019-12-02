//
// Created by tjlaa on 2019-12-01.
//

#include <cmath>
#include <algorithm>
#include <iostream>
#include "Tour.hpp"

double Tour::get_city_distance(City* c1, City* c2) {
    int xDistance = abs((c1 -> get_x()) - (c2 -> get_x()));
    int yDistance = abs((c1 -> get_y()) - (c2 -> get_y()));
    return sqrt(xDistance * xDistance + yDistance * yDistance);
}

double Tour::get_tour_distance() {
    double total_distance = 0;
    for(unsigned int i = 0; i < cities.size() - 1;i++) {
        total_distance += get_city_distance(cities[i], cities[i + 1]);
    }
    return total_distance + get_city_distance(cities[0], cities[cities.size()-1]);
}

void Tour::shuffle_cities() {
    random_device rd;
    default_random_engine generator(rd());

    for(int i = 0;i < 64;i++) {
        shuffle(cities.begin(), cities.end(), generator);
    }
}

ostream& operator<<(ostream& out, const Tour& obj) {
    out << "Fitness: " << obj.fitness << endl;

    for(City* c : obj.cities) {
        out << *c << endl;
    }

    return out;
}