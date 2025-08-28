# tetris-game
A simple Tetris game created in C++ and raylib, demonstrating core game development principles like collision detection, game loop, and object-oriented programming.

# building and running the game locally (macOS - CLionProjects - CLion IDE)
cd ~/CLionProjects/tetris-game                                                                                   newgame_windows
rm -rf build
cmake -S . -B build -DCMAKE_PREFIX_PATH="$(brew --prefix raylib)"
cmake --build build
./build/tetris-game

# building with Dockers (Recommended)