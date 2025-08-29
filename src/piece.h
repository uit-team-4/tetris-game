//
// Created by Hiền on 27/8/25.
//

#ifndef TETRIS_GAME_PIECE_H
#define TETRIS_GAME_PIECE_H

class Piece {
public:
  int row{0};
  int col{0};

private:
  int id_{0};
  int rotation_{0};
};

#endif // TETRIS_GAME_PIECE_H