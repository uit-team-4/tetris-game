// src/grid.h
#pragma once
#include <vector>
#include "raylib.h"

class Grid {
public:
    Grid();

    void Initialize();
    void Print();
    void Draw(Font font, int score);

    bool IsCellOutside(int row, int column) const;
    bool IsCellEmpty(int row, int column) const;

    int  GetCell(int row, int col) const { return grid[row][col]; }
    void SetCell(int row, int col, int value) { grid[row][col] = value; }
    int  Rows() const { return numRows; }
    int  Cols() const { return numCols; }
    int  CellSize() const { return cellSize; }

    int  ClearFullRows();

private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int rows);

    int numRows;
    int numCols;
    int cellSize;

    int grid[20][10];
    std::vector<Color> colors;
};

