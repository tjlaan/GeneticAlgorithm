//
// Created by tjlaa on 2019-12-01.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>
#include <utility>

using namespace std;

class City {
private:
    string name;
    int x;
    int y;
public:
    City(string name, int x, int y) : name(name), x(x), y(y) {}
    string get_name() { return name; }
    int get_x() { return x; }
    int get_y() { return y; }
    friend ostream& operator << (ostream&, const City&);
};


#endif //GENETICALGORITHM_CITY_HPP
