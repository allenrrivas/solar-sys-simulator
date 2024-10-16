#include "raylib.h"
#include "planet.h"
#include <vector>

int main()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Solar System Simulation");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(screenWidth / 2, screenHeight / 2, 40.0f, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}