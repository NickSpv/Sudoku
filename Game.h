#pragma once
#include "Menu.h"
#include "SudokuField.h"

class Game {
public:
    explicit Game(int size_ = 9);
    void startGame();
    void gameWin();

private:
    Menu menu;
    SudokuField sudokuField;
    int size;
    bool isEndGame;
};
