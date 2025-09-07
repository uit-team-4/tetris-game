#include "game.h"
#include "raylib.h"
#include "colors.h"
#include <iostream>

int main() {
  const int screenWidth = 500;
  const int screenHeight = 620;
  const Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

  InitWindow(screenWidth, screenHeight, "Tetris");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    // game.Update();
            UpdateMusicStream(game.music);
        game.HandleInput();
        if (game.isPlaying)
        {
            game.MovePieceDown();
        }

    BeginDrawing();
    ClearBackground(DARKGRAY);
    DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
    DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
    game.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}