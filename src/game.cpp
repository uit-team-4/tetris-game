//
// Created by Hiền on 27/8/25.
//

#include "game.h"
#include "grid.h"

Game::Game() {
  grid = Grid();
  currentBlock = Piece::GetRandomPiece();
}

void Game::Draw() { grid.Draw(); }

bool Game::IsValidPosition() {
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for (Position item : tiles) {
    return grid.IsCellOutside(item.row, item.col);
  }
  return true;
}