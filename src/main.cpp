#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "planet.h"
#include <vector>

int main()
{
    const int screenWidth = 3500;
    const int screenHeight = 1440;
    InitWindow(screenWidth, screenHeight, "Solar System Simulation");

    Camera2D camera = {0};
    camera.zoom = 1.0f;

    int zoomMode = 0;

    // Sun
    Planet sun(0, 0, 30, YELLOW, 1.9882e30);
    sun.sun = true;
    // Mercury
    Planet mercury(0.387 * AU, 0, 8, DARKGRAY, 3.3010e23);
    mercury.y_vel = -47.4 * 1000;
    // Venus
    Planet venus(0.723 * AU, 0, 14, GOLD, 4.8675e24);
    venus.y_vel = -35.02 * 1000;
    // Earth
    Planet earth(-1 * AU, 0, 16, BLUE, 5.9742e24);
    earth.y_vel = 29.783 * 1000;
    // Mars
    Planet mars(1.52 * AU, 0, 12, ORANGE, 6.4171e23);
    mars.y_vel = 24.077 * 1000;
    // Jupiter
    Planet jupiter(5.20 * AU, 0, 24, BROWN, 1.89813e27);
    jupiter.y_vel = 13.06 * 1000;
    // Saturn
    Planet saturn(9.57 * AU, 0, 20, BEIGE, 5.683e26);
    saturn.y_vel = 9.67 * 1000;
    // Uranus
    Planet uranus(19.17 * AU, 0, 18, SKYBLUE, 8.681e25);
    uranus.y_vel = 6.79 * 1000;
    // Neptune
    Planet neptune(30.18 * AU, 0, 17, BLUE, 1.024e26);
    neptune.y_vel = 5.45 * 1000;

    std::vector<Planet> planets = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_ONE))
            zoomMode = 0;
        else if (IsKeyPressed(KEY_TWO))
            zoomMode = 1;

        // Translate based on mouse right click
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f / camera.zoom);
            camera.target = Vector2Add(camera.target, delta);
        }

        if (zoomMode == 0)
        {
            // Zoom based on mouse wheel
            float wheel = GetMouseWheelMove();
            if (wheel != 0)
            {
                // Get the world point that is under the mouse
                Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

                // Set the offset to where the mouse is
                camera.offset = GetMousePosition();

                // Set the target to match, so that the camera maps the world space point
                // under the cursor to the screen space point under the cursor at any zoom
                camera.target = mouseWorldPos;

                // Zoom increment
                float scaleFactor = 1.0f + (0.25f * fabsf(wheel));
                if (wheel < 0)
                    scaleFactor = 1.0f / scaleFactor;
                camera.zoom = Clamp(camera.zoom * scaleFactor, 0.125f, 64.0f);
            }
        }
        else
        {
            // Zoom based on mouse left click
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                // Get the world point that is under the mouse
                Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);

                // Set the offset to where the mouse is
                camera.offset = GetMousePosition();

                // Set the target to match, so that the camera maps the world space point
                // under the cursor to the screen space point under the cursor at any zoom
                camera.target = mouseWorldPos;
            }
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                // Zoom increment
                float deltaX = GetMouseDelta().x;
                float scaleFactor = 1.0f + (0.01f * fabsf(deltaX));
                if (deltaX < 0)
                    scaleFactor = 1.0f / scaleFactor;
                camera.zoom = Clamp(camera.zoom * scaleFactor, 0.125f, 64.0f);
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(camera);

        for (auto &planet : planets)
        {
            planet.update_position(planets);
            planet.draw();
        }

        EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}