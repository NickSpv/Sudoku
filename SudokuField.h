#pragma once

#include <vector>
#include <iostream>
#include <limits>
#include <cmath>
#include <random>
#include <ctime>
#include "CellField.h"
#include "values.h"

class SudokuField {
public:
    SudokuField();
    void generateField(int n);
    void doNextStep();
    bool isEndGame() const;
    bool isExit() const;

private:
    void printField();
    void changeCell();
    void swapCols(int l, int r, bool isTheWholeSection);
    void swapRows(int l, int r, bool isTheWholeSection);
    void transpose();


    std::vector<std::vector<CellField>> fieldMap;
    bool exit;
};
