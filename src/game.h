//
// Created by Hiền on 27/8/25.
//

#ifndef TETRIS_GAME_GAME_H
#define TETRIS_GAME_GAME_H
#include "grid.h"
#include "piece.h"

class Game {
public:
  Game();
  void Draw(Font font);
  bool IsValidPosition();
  void Update();

private:
  Grid grid;
  Piece currentBlock;
  int score;
};

#endif // TETRIS_GAME_GAME_H