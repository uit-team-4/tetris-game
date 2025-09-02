//
// Created by Hiền on 27/8/25.
//

#ifndef TETRIS_GAME_GAME_H
#define TETRIS_GAME_GAME_H
#include "grid.h"

class Game {
public:
  Game();
  void Draw();

private:
  Grid grid;
};

#endif // TETRIS_GAME_GAME_H