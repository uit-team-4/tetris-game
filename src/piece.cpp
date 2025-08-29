//
// Created by Hiền on 27/8/25.
//

#include "piece.h"

LShape::LShape() {
  id = 1;
  cells[0] = {{0, 0}, {1, 0}, {2, 0}, {2, 1}}; // rotation 0
  cells[1] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}}; // rotation 1
  cells[2] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}}; // rotation 2
  cells[3] = {{1, 0}, {1, 1}, {1, 2}, {0, 2}}; // rotation 3
}
