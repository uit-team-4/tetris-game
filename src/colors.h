#pragma once
#include <vector>

// Color definitions for Tetris blocks
extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

// Function to get colors for grid cells
std::vector<Color> GetCellColors();
