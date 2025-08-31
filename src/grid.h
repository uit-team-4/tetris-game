#pragma once
#include "raylib.h"
#include "vector"

class Grid {
public:
  Grid();
  void Initialize();
  void Draw();
  int grid[20][10]{};

private:
  int numRows;
  int numCols;
  int cellSize;
  std::vector<Color> colors;
};