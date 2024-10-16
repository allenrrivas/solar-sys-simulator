#ifndef PLANET_H_
#define PLANET_H_

#include "raylib.h"

#include <iostream>
#include <vector>
#include <string>

const double G = 6.67428e-11;
const double AU = 149.6e6 * 1000;
const double SCALE = 250 / AU;     // 1AU = 100 pixels
const double TIMESTEP = 3600 * 24; // 1 day

class Planet
{
public:
    double x, y;
    double radius;
    Color color;
    double mass;
    std::vector<Vector2> orbit;
    bool sun = false;
    double distance_to_sun = 0;
    double x_vel = 0;
    double y_vel = 0;

    Planet(double x, double y, double radius, Color color, double mass)
        : x(x), y(y), radius(radius), color(color), mass(mass) {}

    Vector2 attarction(const Planet &other);
    void update_position(std::vector<Planet> &planets);
    void draw();
};

#endif