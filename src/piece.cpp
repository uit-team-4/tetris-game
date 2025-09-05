//
// Created by Hiền on 27/8/25.
//

#include "piece.h"
#include "colors.h"
#include <cstdlib>

// init Piece
Piece::Piece() {
  cellSize = 30;
  rotation = 0;
  rowOffset = 0;
  columnOffset = 0;
  Move(0, 1);
}

Piece Piece::GetRandomPiece() {

  // Generate random number 0-6 for 7 different pieces

  switch (rand() % 7) {
  case 0:
    return LShape();
  case 1:
    return SShape();
  case 2:
    return TShape();
  case 3:
    return IShape();
  case 4:
    return OShape();
  case 5:
    return JShape();
  case 6:
    return ZShape();
  default:
    return LShape(); // fallback
  }
}

void Piece::Rotate() { rotation = (rotation + 1) % 4; }

void Piece::Move(int row, int col) {
  rowOffset += row;
  columnOffset += col;
}

void Piece::MoveLeft() { Move(0, -1); }

void Piece::MoveRight() { Move(0, 1); }

void Piece::MoveDown() { Move(1, 0); }

void Piece::Draw(int offsetX, int offsetY) {
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 4; col++) {
      DrawRectangle(offsetX + col * cellSize, offsetY + row * cellSize,
                    cellSize - 1, cellSize - 1, darkGrey);
    }
  }
}

std::vector<Position> Piece::GetCellPositions() {
  std::vector<Position> tiles = cells[rotation];
  std::vector<Position> movedTiles;
  for (Position item : tiles) {
    Position newPos{item.row + rowOffset, item.col + columnOffset};
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}

LShape::LShape() {
  id = 1;
  cells[0] = {{0, 0}, {1, 0}, {2, 0}, {2, 1}}; // rotation 0
  cells[1] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}}; // rotation 1
  cells[2] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}}; // rotation 2
  cells[3] = {{1, 0}, {1, 1}, {1, 2}, {0, 2}}; // rotation 3
}

JShape::JShape() {
  id = 2;
  cells[0] = {{0, 1}, {1, 1}, {2, 0}, {2, 1}}; // rotation 0
  cells[1] = {{0, 0}, {0, 1}, {1, 0}, {2, 0}}; // rotation 1
  cells[2] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}}; // rotation 2
  cells[3] = {{0, 2}, {1, 2}, {2, 1}, {2, 2}}; // rotation 3
}

IShape::IShape() {
  id = 3;
  cells[0] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}}; // rotation 0
  cells[1] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}}; // rotation 1
  cells[2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}}; // rotation 2
  cells[3] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}}; // rotation 3
}

TShape::TShape() {
  id = 4;
  cells[0] = {{0, 1}, {1, 0}, {1, 1}, {1, 2}}; // rotation 0
  cells[1] = {{0, 1}, {1, 1}, {1, 2}, {2, 1}}; // rotation 1
  cells[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 1}}; // rotation 2
  cells[3] = {{0, 1}, {1, 0}, {1, 1}, {2, 1}}; // rotation 3
}

ZShape::ZShape() {
  id = 5;
  cells[0] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}}; // rotation 0
  cells[1] = {{0, 1}, {1, 0}, {1, 1}, {2, 0}}; // rotation 1
  cells[2] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}}; // rotation 2
  cells[3] = {{0, 1}, {1, 0}, {1, 1}, {2, 0}}; // rotation 3
}

SShape::SShape() {
  id = 6;
  cells[0] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}}; // rotation 0
  cells[1] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}}; // rotation 1
  cells[2] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}}; // rotation 2
  cells[3] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}}; // rotation 3
}

OShape::OShape() {
  id = 7;
  cells[0] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // rotation 0
  cells[1] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // rotation 1
  cells[2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // rotation 2
  cells[3] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}; // rotation 3
}
