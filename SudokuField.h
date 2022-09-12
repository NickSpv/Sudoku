#pragma once

#include <vector>
#include <iostream>
#include <cmath>
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

    std::vector<std::vector<CellField>> fieldMap;
    bool exit;
};
