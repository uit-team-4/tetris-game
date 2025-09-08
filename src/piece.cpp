//
// Created by Hiền on 27/8/25.
//

#include "piece.h"
#include "colors.h"
#include <random>

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

// Bổ sung triển khai cho phương thức UndoRotation
void Piece::UndoRotation() {
  rotation = (rotation + 3) % 4;
  if (rotation < 0) {
    rotation = 3;
  }
}

void Piece::Move(int row, int col) {
  rowOffset += row;
  columnOffset += col;
}

void Piece::MoveLeft() { Move(0, -1); }

void Piece::MoveRight() { Move(0, 1); }

void Piece::MoveDown() { Move(1, 0); }

void Piece::Draw(int offsetX, int offsetY) {
  std::vector<Position> tiles = GetCellPositions();
  Color pieceColor = darkGrey;
  std::vector<Color> cellColors = GetCellColors();
  if (id > 0 && id < (int)cellColors.size()) {
    pieceColor = cellColors[id];
  }
  for (const auto &item : tiles) {
    DrawRectangle(item.col * cellSize + offsetX, item.row * cellSize + offsetY,
                  cellSize - 1, cellSize - 1, pieceColor);
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
  cells[0] = {{0, 2}, {1, 0}, {1, 1}, {1, 2}};
  cells[1] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}};
  cells[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 0}};
  cells[3] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
  Move(0, 3);
}

JShape::JShape() {
  id = 2;
  cells[0] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
  cells[1] = {{0, 1}, {0, 2}, {1, 1}, {2, 1}};
  cells[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}};
  cells[3] = {{0, 1}, {1, 1}, {2, 0}, {2, 1}};
  Move(0, 3);
}

IShape::IShape() {
  id = 3;
  cells[0] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};
  cells[1] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
  cells[2] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
  cells[3] = {{0, 1}, {1, 1}, {2, 1}, {3, 1}};
  Move(-1, 3);
}

TShape::TShape() {
  id = 4;
  cells[0] = {{0, 1}, {1, 0}, {1, 1}, {1, 2}};
  cells[1] = {{0, 1}, {1, 1}, {1, 2}, {2, 1}};
  cells[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 1}};
  cells[3] = {{0, 1}, {1, 0}, {1, 1}, {2, 1}};
  Move(0, 3);
}

ZShape::ZShape() {
  id = 5;
  cells[0] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
  cells[1] = {{0, 2}, {1, 1}, {1, 2}, {2, 1}};
  cells[2] = {{1, 0}, {1, 1}, {2, 1}, {2, 2}};
  cells[3] = {{0, 1}, {1, 0}, {1, 1}, {2, 0}};
  Move(0, 3);
}

SShape::SShape() {
  id = 6;
  cells[0] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}};
  cells[1] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}};
  cells[2] = {{1, 1}, {1, 2}, {2, 0}, {2, 1}};
  cells[3] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
  Move(0, 3);
}

OShape::OShape() {
  id = 7;
  cells[0] = {{0, 1}, {0, 2}, {1, 1}, {1, 2}};
  cells[1] = {{0, 1}, {0, 2}, {1, 1}, {1, 2}};
  cells[2] = {{0, 1}, {0, 2}, {1, 1}, {1, 2}};
  cells[3] = {{0, 1}, {0, 2}, {1, 1}, {1, 2}};
  Move(0, 4);
}
