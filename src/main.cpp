#include "colors.h"
#include "game.h"
#include "raylib.h"
#include <iostream>

int main() {
  const int screenWidth = 500;
  const int screenHeight = 620;
  const Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

  InitWindow(screenWidth, screenHeight, "Tetris");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    UpdateMusicStream(game.music);
    game.Update(); // Toàn bộ logic cập nhật game nằm trong hàm này

    BeginDrawing();
    ClearBackground(darkGrey);
    game.Draw(font);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}