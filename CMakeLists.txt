cmake_minimum_required(VERSION 3.16)
project(tetris-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Only build on Windows
if(WIN32)
# Raylib paths
set(RAYLIB_INCLUDE_DIR "C:\\raylib\\w64devkit\\x86_64-w64-mingw32\\include")
set(RAYLIB_LIB_DIR "C:\\raylib\\w64devkit\\x86_64-w64-mingw32\\lib")
    # Add your source files
    add_executable(tetris-game
        src/main.cpp
        src/game.cpp
        #src/piece.cpp
        src/grid.cpp
        src/colors.cpp
    )

    # Link Raylib and required Windows libraries
    target_link_libraries(tetris-game raylib
        winmm
        gdi32
        opengl32
    )

        # Include Raylib headers
        target_include_directories(tetris-game PRIVATE ${RAYLIB_INCLUDE_DIR})

        # Link Raylib and Windows system libraries
        target_link_directories(tetris-game PRIVATE ${RAYLIB_LIB_DIR})
        target_link_libraries(tetris-game raylib winmm gdi32 opengl32)
else()
        add_executable(tetris-game
                src/main.cpp
                src/grid.cpp
        )

        target_include_directories(tetris-game PRIVATE
                ${CMAKE_SOURCE_DIR}/src
        )

        find_package(raylib REQUIRED)
        target_link_libraries(tetris-game PRIVATE raylib)

endif()
