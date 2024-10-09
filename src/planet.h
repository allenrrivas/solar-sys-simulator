#ifndef PLANET_H_
#define PLANET_H_

#include <iostream>
#include <string>

class Planet{
public:
    void planet_details();
private:
    std::string name;
    double mass;
    double radius;
    double distance_from_sun;
};

#endif