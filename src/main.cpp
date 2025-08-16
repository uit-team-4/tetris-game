#include <raylib.h>
int main()
{
    // Initialize the window
    InitWindow(800, 450, "Hello raylib!"); // width, height, title

    // Set the target frames per second (optional, but good practice)
    SetTargetFPS(30);

    // Main game loop
    while (!WindowShouldClose()) // Loop until the window is closed
    {
        // Drawing
        BeginDrawing(); // Start drawing operations
        ClearBackground(RAYWHITE); // Clear the background with a color
        DrawText("Hello World!", 190, 200, 20, BLACK); // Draw text on screen
        EndDrawing(); // End drawing operations
    }

    // Close the window and unload resources
    CloseWindow();

    return 0;
}
