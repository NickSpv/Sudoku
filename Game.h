#pragma once

#include "Menu.h"
#include "SudokuField.h"

class Game {
public:
    explicit Game();
    void startGame();
    void gameWin();

private:
    Menu menu;
    SudokuField sudokuField;
    bool isEndGame;
};
