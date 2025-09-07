#include "game.h"
#include "raylib.h"
int main() {
  const int screenWidth = 500;
  const int screenHeight = 620;
  Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
  InitWindow(screenWidth, screenHeight, "Tetris");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    // game.Update();
    BeginDrawing();
    ClearBackground(DARKGRAY);
    game.Draw(font);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}