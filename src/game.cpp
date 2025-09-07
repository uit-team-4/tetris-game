//
// Created by Hiền on 27/8/25.
//

#include "game.h"
#include "grid.h"
#include <algorithm>
#include <vector>

// --- Constructor & Destructor ---
Game::Game() {
  grid = Grid();
  gameOver = false;
  score = 0;
  fallTimer = 0;
  fallInterval = 0.5;

  InitAudioDevice();
  music = LoadMusicStream("sounds/music.mp3");
  PlayMusicStream(music);
  rotateSound = LoadSound("sounds/rotate.mp3");
  clearSound = LoadSound("sounds/clear.mp3");

  currentPiece = Piece::GetRandomPiece();
  nextPiece = Piece::GetRandomPiece();
}

Game::~Game() {
  UnloadSound(rotateSound);
  UnloadSound(clearSound);
  UnloadMusicStream(music);
  CloseAudioDevice();
}

// --- Vòng lặp chính của Game ---
void Game::Update() {
  if (gameOver) {
    if(IsKeyPressed(KEY_ENTER)){
      Reset();
    }
    return;
  }

  HandleInput();

  if (IsKeyDown(KEY_DOWN)) {
      fallInterval = 0.1f;
  } else {
      fallInterval = 0.5f;
  }

  fallTimer += GetFrameTime();
  if (fallTimer >= fallInterval) {
    fallTimer = 0.0f;
    MovePieceDown();
  }
}

void Game::Draw(Font font) {
  grid.Draw(font, score);
  currentPiece.Draw(11, 11);

    switch (nextPiece.id) {
        case 3:
            nextPiece.Draw(285, 280);
            break;
        case 7:
            nextPiece.Draw(285, 270);
            break;
        default:
            nextPiece.Draw(300, 270);
            break;
    }
  if(gameOver){
      DrawRectangle(0, 0, 500, 620, Fade(BLACK, 0.7f));
      const char* gameOverText = "GAME OVER";
      Vector2 gameOverSize = MeasureTextEx(font, gameOverText, 40, 2);
      float gameOverX = 11 + (300 - gameOverSize.x) / 2;
      DrawTextEx(font, gameOverText, {gameOverX, 180}, 40, 2, RED);
      const char* hsTitleText = "High Scores";
      Vector2 hsTitleSize = MeasureTextEx(font, hsTitleText, 32, 2);
      float hsTitleX = 11 + (300 - hsTitleSize.x) / 2;
      DrawTextEx(font, hsTitleText, {hsTitleX, 250}, 32, 2, WHITE);
      for (size_t i = 0; i < highScores.size(); ++i) {
          const char* scoreText = TextFormat("%d. %d", i + 1, highScores[i]);
          Vector2 scoreSize = MeasureTextEx(font, scoreText, 28, 2);
          float scoreX = 11 + (300 - scoreSize.x) / 2;
          DrawTextEx(font, scoreText, {scoreX, 300 + (float)i * 40}, 28, 2, LIGHTGRAY);
      }
      const char* restartText = "Press ENTER to restart";
      Vector2 restartSize = MeasureTextEx(font, restartText, 20, 2);
      float restartX = 11 + (300 - restartSize.x) / 2;
      DrawTextEx(font, restartText, {restartX, 520}, 20, 2, LIGHTGRAY);
  }
}

// --- Xử lý Input ---
void Game::HandleInput() {
    int keyPressed = GetKeyPressed();
    switch (keyPressed) {
    case KEY_LEFT:
        MovePieceLeft();
        break;
    case KEY_RIGHT:
        MovePieceRight();
        break;
    case KEY_DOWN:
        MovePieceDown();
        break;
    case KEY_UP:
        RotatePiece();
        break;
    }
}

void Game::MovePieceLeft(){ if(gameOver) return; currentPiece.Move(0, -1); if(!IsValidPosition()){ currentPiece.Move(0, 1); } }
void Game::MovePieceRight(){ if(gameOver) return; currentPiece.Move(0, 1); if(!IsValidPosition()){ currentPiece.Move(0, -1); } }
void Game::MovePieceDown() { if (gameOver) return; currentPiece.Move(1, 0); if(!IsValidPosition()){ currentPiece.Move(-1, 0); LockPiece(); } }
void Game::RotatePiece(){ if(gameOver) return; currentPiece.Rotate(); if(!IsValidPosition()){ currentPiece.UndoRotation(); } else { PlaySound(rotateSound); } }
bool Game::IsValidPosition() { std::vector<Position> tiles = currentPiece.GetCellPositions(); for (const auto& item : tiles) { if (grid.IsCellOutside(item.row, item.col) || !grid.IsCellEmpty(item.row, item.col)) { return false; } } return true; }

// --- Logic Game (Không đổi) ---
void Game::LockPiece(){ std::vector<Position> tiles = currentPiece.GetCellPositions(); for(const auto& item : tiles){ grid.SetCell(item.row, item.col, currentPiece.id); } currentPiece = nextPiece; nextPiece = Piece::GetRandomPiece(); int rowsCleared = grid.ClearFullRows(); if(rowsCleared > 0){ PlaySound(clearSound); UpdateScore(rowsCleared, 0); } if(!IsValidPosition()){ gameOver = true; UpdateHighScores(); } }
void Game::Reset() { grid.Initialize(); currentPiece = Piece::GetRandomPiece(); nextPiece = Piece::GetRandomPiece(); score = 0; gameOver = false; }
void Game::UpdateScore(int linesCleared, int moveDownPoints) { switch (linesCleared) { case 1: score += 100; break; case 2: score += 300; break; case 3: score += 500; break; default: break; } score += moveDownPoints; }

void Game::UpdateHighScores() {
    highScores.push_back(score);
    std::sort(highScores.begin(), highScores.end(), std::greater<int>());
    if (highScores.size() > 5) {
        highScores.resize(5);
    }
}