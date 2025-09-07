#include "grid.h"
#include "colors.h"

Grid::Grid() {
  numRows = 20;
  numCols = 10;
  cellSize = 30;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numCols; column++) {
      grid[row][column] = 0;
    }
  }
}

void Grid::Draw(Font font, int score) {
  // Draw the game grid
  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numCols; column++) {
      int cellValue = grid[row][column];
      DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }

  // Draw UI elements
  // Draw "Score" label
  DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);

  // Draw "Next" label
  DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);

  // Draw score background rectangle
  DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

  // Draw score text
  char scoreText[10];
  sprintf(scoreText, "%d", score);
  Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
  DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

  // Draw next piece background rectangle
  DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
}

bool Grid::IsCellOutside(int row, int column) {
  return row < 0 || row >= numRows || column < 0 || column >= numCols;
}

bool Grid::IsCellEmpty(int row, int column) { return grid[row][column] == 0; }