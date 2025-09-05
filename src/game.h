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
  void Draw();
  bool IsValidPosition();
  void Update();

private:
  Grid grid;
  Piece currentBlock;
};

#endif // TETRIS_GAME_GAME_H