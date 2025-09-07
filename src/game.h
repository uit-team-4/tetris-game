//
// Created by Hiền on 27/8/25.
//

#ifndef TETRIS_GAME_GAME_H
#define TETRIS_GAME_GAME_H
#pragma once
#include "grid.h"
#include "piece.h"

class Game {
public:
  Game();
  ~Game();
  void Draw(Font font);
  bool IsValidPosition();
  void Update();
  void MovePieceDown();
  void HandleInput();
  Music music;
  bool isPlaying;

private:
  bool gameOver;
  int score;
  Grid grid;
  Piece currentBlock;
  Piece currentPiece;
  Piece nextPiece;
  void MovePieceLeft();
  void MovePieceRight();
  bool IsPieceOutside();
  void RotatePiece();
  void LockPiece();
  bool PieceFits();
  void Reset();
  void UpdateScore(int linesCleared, int moveDownPoints);
  std::vector<Piece> pieces;
  Sound rotateSound;
  Sound clearSound;
};

#endif // TETRIS_GAME_GAME_H