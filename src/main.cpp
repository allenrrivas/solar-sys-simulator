#include "raylib.h"
#include "planet.h"
#include <vector>

int main()
{
    const int screenWidth = 3500;
    const int screenHeight = 1440;
    InitWindow(screenWidth, screenHeight, "Solar System Simulation");

    // Sun
    Planet sun(0, 0, 30, YELLOW, 1.9882e30);
    sun.sun = true;
    // Mercury
    Planet mercury(0.387 * AU, 0, 8, DARKGRAY, 3.3010e23);
    // Venus
    Planet venus(0.723 * AU, 0, 14, GOLD, 4.8675e24);
    // Earth
    Planet earth(-1 * AU, 0, 16, BLUE, 5.9742e24);
    // Mars
    Planet mars(1.52 * AU, 0, 12, ORANGE, 6.4171e23);
    // Jupiter
    Planet jupiter(5.20 * AU, 0, 24, BROWN, 1.89813e27);
    // Saturn
    Planet saturn(9.57 * AU, 0, 20, BEIGE, 5.683e26);
    // Uranus
    Planet uranus(19.17 * AU, 0, 18, SKYBLUE, 8.681e25);
    // Neptune
    Planet neptune(30.18 * AU, 0, 17, BLUE, 1.024e26);

    std::vector<Planet> planets = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i <= planets.size(); i++)
        {
            planets[i].draw();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}