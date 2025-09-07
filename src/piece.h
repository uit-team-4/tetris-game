//
// Created by Hiền on 27/8/25.
//
#ifndef TETRIS_GAME_PIECE_H
#define TETRIS_GAME_PIECE_H
#pragma once
#include "map"
#include "vector"

using namespace std;

struct Position {
  int row;
  int col;
};

class Piece {
public:
  Piece();
  int id;
  int cellSize;
  map<int, vector<Position>> cells;
  static Piece GetRandomPiece();
  void Rotate();
  void UndoRotation(); // Thêm phương thức để quay ngược lại
  void Move(int row, int col);
  void MoveLeft();
  void MoveRight();
  void MoveDown();
  void Draw(int offsetX, int offsetY);
  std::vector<Position> GetCellPositions();

private:
  int row;
  int col;
  int rotation;
  int rowOffset;
  int columnOffset;
};

class LShape : public Piece {
public:
  LShape();
};

class JShape : public Piece {
public:
  JShape();
};

class IShape : public Piece {
public:
  IShape();
};

class TShape : public Piece {
public:
  TShape();
};

class ZShape : public Piece {
public:
  ZShape();
};

class SShape : public Piece {
public:
  SShape();
};

class OShape : public Piece {
public:
  OShape();
};

#endif // TETRIS_GAME_PIECE_H
