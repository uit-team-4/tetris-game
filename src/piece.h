//
// Created by Hiền on 27/8/25.
//
#ifndef TETRIS_GAME_PIECE_H
#define TETRIS_GAME_PIECE_H
#include "map"
#include "vector"

using namespace std;

struct Position {
  int row;
  int col;
};

class Piece {
public:
  int id;
  map<int, vector<Position>> cells;

private:
  int row;
  int col;
  int rotation;
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