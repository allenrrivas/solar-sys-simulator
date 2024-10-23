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

    return {static_cast<float>(fx), static_cast<float>(fy)};
};

void Planet::update_position(std::vector<Planet> &planets)
{
    double total_fx = 0;
    double total_fy = 0;

    for (auto &planet : planets)
    {
        if (this == &planet)
            continue;
        auto force = attarction(planet);
        total_fx += force.x;
        total_fy += force.y;
    }

    x_vel += total_fx / mass * TIMESTEP;
    y_vel += total_fy / mass * TIMESTEP;

    x += x_vel * TIMESTEP;
    y += y_vel * TIMESTEP;

    orbit.push_back({static_cast<float>(x * SCALE + WIDTH / 2), static_cast<float>(y * SCALE + HEIGHT / 2)});
}

void Planet::draw()
{
    double x_ = x * SCALE + WIDTH / 2;
    double y_ = y * SCALE + HEIGHT / 2;
    DrawCircle(x_, y_, radius, color);

    // Draw the orbit trail
    if (orbit.size() > 2)
    {
        for (size_t i = 1; i < orbit.size(); i++)
        {
            DrawLineV(orbit[i - 1], orbit[i], color);
        }
    }
}