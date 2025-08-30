#include "raylib.h"
#include "game.h"

int main() {
    const int screenWidth  = 500;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    // Game game;

    while (!WindowShouldClose()) {
        // game.Update();
        BeginDrawing();
        ClearBackground(DARKGRAY);
        // game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}