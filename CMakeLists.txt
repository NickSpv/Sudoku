cmake_minimum_required(VERSION 3.22.2)
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
        values.h)

add_executable(Sudoku ${HEADERS} ${SOURCES})
