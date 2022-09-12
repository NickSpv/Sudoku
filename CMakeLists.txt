cmake_minimum_required(VERSION 3.23)
project(Sudoku)

set(CMAKE_CXX_STANDARD 14)

set(HEADERS
        SudokuField.h
        Game.h
        CellField.h
        Menu.h
        )

set(SOURCES
        main.cpp
        SudokuField.cpp
        Game.cpp
        CellField.cpp
        Menu.cpp
        )

add_executable(Sudoku ${HEADERS} ${SOURCES})
