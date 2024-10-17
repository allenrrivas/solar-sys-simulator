#include "raylib.h"
#include "planet.h"
#include <vector>

int main()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Solar System Simulation");

    Planet sun(0, 0, 30, YELLOW, 1.9882e30);
    sun.sun = true;

    Planet earth(-1 * AU, 0, 16, BLUE, 5.9742e24);

    std::vector<Planet> planets = {sun, earth};

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