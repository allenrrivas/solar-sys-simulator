#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Solar System Simulator");

    // Define the camera to look into our 3d world
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f}; // Camera position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                              // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;           // Camera projection type

    Vector3 sunPosition = {0.0f, 0.0f, 0.0f};
    Vector3 mercuryPosition = {200.0f, 0.0f, 0.0f};
    Vector3 venusPosition = {400.0f, 0.0f, 0.0f};

    DisableCursor(); // Limit cursor to relative movement inside the window

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed('Z'))
            camera.target = (Vector3){0.0f, 0.0f, 0.0f};
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawSphere(sunPosition, 140.0f, ORANGE);
        DrawSphere(mercuryPosition, 0.488f, RED);
        DrawSphere(venusPosition, 1.2104f, BLUE);
        DrawCubeWires(sunPosition, 2.0f, 2.0f, 2.0f, MAROON);

        DrawGrid(10, 1.0f);

        EndMode3D();

        DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}