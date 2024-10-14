#include "raylib.h"
#include "planet.h"
#include "cmath"

void Planet::planet_info()
{

    DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 250, 113, BLUE);

    DrawText("Name:", 40, 20, 10, WHITE);
    DrawText("Mass: ", 40, 40, 10, WHITE);
    DrawText("Radius: ", 40, 60, 10, WHITE);
    DrawText("Rotation Period: ", 40, 80, 10, WHITE);
    DrawText("Distance from Sun: ", 40, 100, 10, WHITE);

    std::cout << "Name: " << name << std::endl;
    std::cout << "Mass: " << mass << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Rotation Period: " << rotation_period << std::endl;
    std::cout << "Distance from Sun: " << distance_from_sun << std::endl;
}

double Planet::cal_gravitational_force(double other_mass, double distance)
{
    const double G = 6.67430e-11;
    return G * (mass * other_mass) / std::pow(distance, 2);
}

double Planet::cal_rotations(double time)
{
    return time / rotation_period;
}

// void display_planet()
// {
//     Planet sun("Sun", 1.989e30, 6.95e5, 2.16e6, 0);
//     // Planet earth("Earth", 5.972e24, 6.371e6, 86400, 1.496e11);

//     Vector3 sunPosition = {0.0f, 0.0f, 0.0f};

//     rlPushMatrix();
//     rlScalef(sun.get_radius() / 5000, sun.get_radius() / 5000, sun.get_radius() / 5000);
//     DrawSphere(sunPosition, sun.get_radius() / 5000, ORANGE);
//     rlPopMatrix();

//     // rlPushMatrix();
//     // rlTranslatef(earth.cal_rotations(7.603e6), 0.0f, 0.0f);
//     // rlRotatef(earth.cal_gravitational_force(sun.get_radius(), 1.49e8), 0.0f, 0.0f, 0.0f);
//     // rlPopMatrix();
// }