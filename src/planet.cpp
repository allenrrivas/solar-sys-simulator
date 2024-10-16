#include "planet.h"
#include <cmath>

Vector2 Planet::attarction(const Planet &other)
{
    double other_x = other.x;
    double other_y = other.y;
    double distance_x = other_x - x;
    double distance_y = other_y - y;
    double distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));

    if (other.sun)
    {
        distance_to_sun = distance;
    }

    double force = G * mass * other.mass / pow(distance, 2);
    double theta = atan2(distance_y, distance_x);
    double fx = cos(theta) * force;
    double fy = sin(theta) * force;

    return {fx, fy};
};

void Planet::update_position(std::vector<Planet> &planets) {}

void Planet::draw() {}