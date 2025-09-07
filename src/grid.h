#pragma once
#include "raylib.h"
#include "vector"

class Grid {
public:
  Grid();
  void Initialize();
  void Draw(Font font, int score);
  int grid[20][10]{};
  bool IsCellOutside(int row, int column);
  bool IsCellEmpty(int row, int column);

private:
  int numRows;
  int numCols;
  int cellSize;
  std::vector<Color> colors;
};