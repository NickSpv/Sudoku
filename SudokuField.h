#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include "CellField.h"
#include "values.h"

class SudokuField {
public:
    void generateField(int n);
    void doNextStep();
    bool isEndGame();

private:
    void printField();
    void changeCell();

    std::vector<std::vector<CellField>> fieldMap;
    std::string header;
};
