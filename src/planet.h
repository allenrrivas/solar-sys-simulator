#ifndef PLANET_H_
#define PLANET_H_

#include <iostream>
#include <string>

class Planet
{
public:
    // Constructor
    Planet(std::string planet_name, double planet_mass, double planet_radius, double planet_rotation_period, double planet_distance_from_sun)
        : name(planet_name), mass(planet_mass), radius(planet_radius), rotation_period(planet_rotation_period), distance_from_sun(planet_distance_from_sun) {}

    // Getters
    std::string get_name() const { return name; }
    double get_mass() const { return mass; }
    double get_radius() const { return radius; }
    double get_distance_from_sun() const { return distance_from_sun; }
    double get_rotation_period() const { return rotation_period; }

    // Setters
    void set_name(std::string planet_name) { name = planet_name; }
    void set_mass(double planet_mass) { mass = planet_mass; }
    void set_radius(double planet_radius) { radius = planet_radius; }
    void set_distance_from_sun(double planet_distance_from_sun) { distance_from_sun = planet_distance_from_sun; }
    void set_rotation_perios(double planet_rotation_period) { rotation_period = planet_rotation_period; }

    void planet_info();
    double cal_gravitational_force(double other_mass, double distance);
    double cal_rotations(double time);

private:
    std::string name;
    double mass;
    double radius;
    double rotation_period;
    double distance_from_sun;
};

#endif