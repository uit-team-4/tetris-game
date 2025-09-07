//
// Created by Hiền on 27/8/25.
//
#pragma once
#include "game.h"
#include "grid.h"

Game::Game() {
  grid = Grid();
  isPlaying = false;
  currentPiece = Piece::GetRandomPiece();
  nextPiece = Piece::GetRandomPiece();
  pieces;
  gameOver = false;
  score = 0;
  InitAudioDevice();
  music = LoadMusicStream("sounds/music.mp3");
  PlayMusicStream(music);
  rotateSound = LoadSound("sounds/rotate.mp3");
  clearSound = LoadSound("sounds/clear.mp3");

}
Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}


void Game::Draw() { 
  grid.Draw(); 
  currentPiece.Draw(11, 11);
  nextPiece.Draw(350, 250);
  // switch (nextPiece.id)
  // {
  // case 3:
  //   nextPiece.Draw(300, 290);
  //   break;
  // case 4:
  //   nextPiece.Draw(300, 280);
  //   break;
  // default:
  //   nextPiece.Draw(315, 270);
  //   break;
  // }
}

bool Game::IsValidPosition() {
  std::vector<Position> tiles = currentPiece.GetCellPositions();
  for (Position item : tiles) {
    return !grid.IsCellOutside(item.row, item.col) ||
           !grid.IsCellEmpty(item.row, item.col);
  }
  return true;
}

void Game::HandleInput() {
  int keyPressed = GetKeyPressed();
  switch (keyPressed) {
  case KEY_LEFT:
  case 'A':
    currentPiece.MoveLeft();
    break;
  case KEY_RIGHT:
  case 'D':
    currentPiece.MoveRight();
    break;
  case KEY_DOWN:
  case 'S':
    currentPiece.MoveDown();
    break;
  case KEY_UP:
  case 'W':
    PlaySound(rotateSound);
    currentPiece.Rotate();
    break;
  case KEY_SPACE:
    isPlaying = !isPlaying;
    break;
  }
}
void Game::MovePieceDown() {
  if (gameOver) {
    return;
  }
  currentPiece.MoveDown();
} 
void Game::MovePieceLeft(){}

void Game::MovePieceRight(){}
bool Game::IsPieceOutside(){}
void Game::RotatePiece(){}
void Game::LockPiece(){
}
bool Game::PieceFits(){
  return false;
}
void Game::Reset(){
}
void Game::UpdateScore(int linesCleared, int moveDownPoints){}