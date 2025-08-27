# tetris-game
A simple Tetris game created in C++ and raylib, demonstrating core game development principles like collision detection, game loop, and object-oriented programming.

# building and running the game locally (macOS - CLionProjects - CLion IDE)
cmake -S . -B build -DCMAKE_PREFIX_PATH="$(brew --prefix raylib)"                                                                main
cmake --build build
./build/tetris-game