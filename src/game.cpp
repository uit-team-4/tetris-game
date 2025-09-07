//
// Created by Hiền on 27/8/25.
//

#include "game.h"
#include "grid.h"

Game::Game() {
  grid = Grid();
  currentBlock = Piece::GetRandomPiece();
  score = 0;
}

void Game::Draw(Font font) { grid.Draw(font, score); }

bool Game::IsValidPosition() {
  std::vector<Position> tiles = currentBlock.GetCellPositions();
  for (Position item : tiles) {
    return !grid.IsCellOutside(item.row, item.col) ||
           !grid.IsCellEmpty(item.row, item.col);
  }
  return true;
}

void Game::Update() {
  int keyPressed = GetKeyPressed();
  switch (keyPressed) {
  case KEY_LEFT:
    currentBlock.MoveLeft();
    break;
  case KEY_RIGHT:
    currentBlock.MoveRight();
    break;
  case KEY_DOWN:
    currentBlock.MoveDown();
    break;
  case KEY_UP:
    currentBlock.Rotate();
    break;
  }
}