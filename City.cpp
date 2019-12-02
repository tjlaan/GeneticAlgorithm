//
// Created by tjlaa on 2019-12-01.
//

#include <iostream>
#include "City.hpp"

ostream& operator<<(ostream& out, const City& obj) {
    out << obj.name << " x:" << obj.x << " y:" << obj.y << " ";
    return out;
}