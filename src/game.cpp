//
// Created by Hiền on 27/8/25.
//

#include "game.h"
#include "grid.h"

Game::Game() { grid = Grid(); }

void Game::Draw() { grid.Draw(); }