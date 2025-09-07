//
// Created by Hiền on 27/8/25.
//

#ifndef TETRIS_GAME_GAME_H
#define TETRIS_GAME_GAME_H
#pragma once
#include "grid.h"
#include "piece.h"
#include <vector>

class Game {
public:
    Game();
    ~Game();
    void Draw(Font font);
    void Update();
    void HandleInput();
    Music music;

private:
    void MovePieceDown();
    void MovePieceLeft();
    void MovePieceRight();
    void RotatePiece();

    bool IsValidPosition();
    void LockPiece();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);

    void UpdateHighScores();

    bool gameOver;
    int score;
    Grid grid;
    Piece currentPiece;
    Piece nextPiece;

    Sound rotateSound;
    Sound clearSound;

    float fallTimer;
    float fallInterval;

    std::vector<int> highScores;
};

#endif