// src/grid.cpp
#include "grid.h"
#include <iostream>

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    // Khởi tạo danh sách màu trực tiếp để đơn giản hóa code
    colors = {DARKGRAY, YELLOW, GREEN, RED, BLUE, ORANGE, PURPLE, SKYBLUE};
}

void Grid::Initialize() {
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            grid[r][c] = 0;
        }
    }
}

void Grid::Print() {
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) std::cout << grid[r][c] << ' ';
        std::cout << '\n';
    }
}

void Grid::Draw(Font font, int score) {
    // Vẽ lưới game
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            int cellValue = grid[r][c];
            // Đảm bảo giá trị 'cellValue' nằm trong phạm vi hợp lệ của mảng 'colors'
            if (cellValue < 0 || cellValue >= (int)colors.size()) cellValue = 0;
            DrawRectangle(c * cellSize + 11, r * cellSize + 11, cellSize - 1,
                          cellSize - 1, colors[cellValue]);
        }
    }

    // Vẽ các thành phần UI
    DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
    DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);

    // Vẽ nền cho điểm số
    DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, SKYBLUE);

    // Vẽ điểm số (sử dụng TextFormat của Raylib để an toàn hơn)
    const char* scoreText = TextFormat("%d", score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

    // Vẽ nền cho khối tiếp theo
    DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, SKYBLUE);
}

bool Grid::IsCellOutside(int row, int column) const {
    return row < 0 || row >= numRows || column < 0 || column >= numCols;
}

bool Grid::IsCellEmpty(int row, int column) const {
    return grid[row][column] == 0;
}

int Grid::ClearFullRows() {
    int completed = 0;
    for (int r = numRows - 1; r >= 0; --r) {
        bool full = true;
        for (int c = 0; c < numCols; ++c) {
            if (grid[r][c] == 0) {
                full = false;
                break;
            }
        }
        if (full) {
            ClearRow(r);
            completed++;
        } else if (completed > 0) {
            MoveRowDown(r, completed);
        }
    }
    return completed;
}

void Grid::ClearRow(int row) {
    for (int c = 0; c < numCols; ++c) {
        grid[row][c] = 0;
    }
}

void Grid::MoveRowDown(int row, int rows) {
    for (int c = 0; c < numCols; ++c) {
        grid[row + rows][c] = grid[row][c];
        grid[row][c] = 0;
    }
}

