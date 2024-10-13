#include "planet.h"

void Planet::planet_details()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Mass: " << mass << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Distance from Sun: " << distance_from_sun << std::endl;
}

double Planet::cal_gravitational_force(double other_mass, double distance)
{
    return 0;
}
