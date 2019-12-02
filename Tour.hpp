//
// Created by tjlaa on 2019-12-01.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include <random>
#include "City.hpp"

using namespace std;

static int TOUR_NUM = 0;

class Tour {
private:
    string name;
    double fitness;
    vector<City*> cities;
    double get_city_distance(City*, City*) const;
    void shuffle_cities();
    bool contains_city(City*);
public:
    Tour(Tour* parent1, Tour* parent2);
    Tour(vector<City*> cities) : cities(cities) {
        name = "Tour " + to_string(TOUR_NUM++);
        shuffle_cities();
        fitness = 1/get_tour_distance() * 10000;
    }
    Tour(const Tour& other);
    ~Tour() = default;
    Tour& operator= (Tour rhs);
    friend void mySwap(Tour&, Tour&);
    void mutate();
    double get_tour_distance() const;
    double get_fitness() { return fitness; };
    vector<City*> get_route() { return cities; };
    friend ostream& operator << (ostream&, const Tour&);
};


#endif //GENETICALGORITHM_TOUR_HPP
