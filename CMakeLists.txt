cmake_minimum_required(VERSION 3.16)
project(tetris-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(tetris-game
        src/main.cpp
        src/game.cpp
        src/grid.cpp
        src/piece.cpp
        src/colors.cpp
)

target_include_directories(tetris-game PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

find_package(raylib REQUIRED)
target_link_libraries(tetris-game PRIVATE raylib)
