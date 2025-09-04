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

void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int column = 0; column < numCols; column++) {
      int cellValue = grid[row][column];
      DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(int row, int column) {
  return row < 0 || row >= numRows || column < 0 || column >= numCols;
}

bool Grid::IsCellEmpty(int row, int column) { return grid[row][column] == 0; }