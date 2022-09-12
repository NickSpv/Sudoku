#include "SudokuField.h"

SudokuField::SudokuField() {
    this->exit = false;
}

void SudokuField::generateField(int n) {
    this->fieldMap = std::vector<std::vector<CellField>>(n, std::vector<CellField>(n, CellField(10)));

    // TODO
    // сделать генерацию поля с однозначным решением

}

void SudokuField::printField() {
    system("clear");
    std::cout << setSecondText << "Чтобы завершить игру введите -1.\n" << setTableText;

    int n = (int) this->fieldMap.size();
    int rectSize = (int) pow((double) n, 0.5);
    std::string spaces = "                 ";

    std::cout << spaces << "╔";
    for (int j = 0; j < n - 1; j++) std::cout << (((j + 1) % rectSize == 0) ? "════╦" : "════╤");
    std::cout << "════╗";

    for (int i = 0; i < n; i++) {
        std::cout << "\n" << spaces << "║ ";
        for (int j = 0; j < n; j++) {
            if (this->fieldMap[i][j].isDefaultCell()) {
                std::cout << setMainText << this->fieldMap[i][j].getRealValue() << setTableText;
            } else {
                std::cout << setSecondMainText << this->fieldMap[i][j].getRealValue() << setTableText;
            }
            if (this->fieldMap[i][j].getRealValue() < 10) std::cout << " ";
            std::cout << (((j + 1) % rectSize == 0) ? " ║ " : " │ ");
        }

        if (i < n - 1) {
            std::cout << "\n" << spaces << (((i + 1) % rectSize == 0) ? "╠" : "╟");
            for (int j = 0; j < n - 1; j++) {
                if ((i + 1) % rectSize == 0) {
                    std::cout << (((j + 1) % rectSize == 0) ? "════╬" : "════╪");
                } else {
                    std::cout << (((j + 1) % rectSize == 0) ? "────╫" : "────┼");
                }
            }
            std::cout << (((i + 1) % rectSize == 0) ? "════╣" : "────╢");
        } else {
            std::cout << "\n" << spaces << "╚";
            for (int j = 0; j < n - 1; j++) {
                std::cout << (((j + 1) % rectSize == 0) ? "════╩" : "════╧");
            }
            std::cout << "════╝\n";
        }
    }
    std::cout << setMainText;
}

void SudokuField::changeCell() {
    std::vector<int> changedCell(3);
    std::cout << "Введите номер координаты и значение ячейки котрую вы хотите изменить: ";

    std::cin >> changedCell[0];
    if (changedCell[0] == -1) {
        this->exit = true;
        return;
    }
    std::cin >> changedCell[1] >> changedCell[2];
    int n = (int) this->fieldMap.size();
    if (changedCell[0] > n || changedCell[0] <= 0 || changedCell[1] > n || changedCell[1] <= 0 || changedCell[2] > n ||
        changedCell[2] <= 0) {
        return;
    }
    if (!this->fieldMap[changedCell[0] - 1][changedCell[1] - 1].isDefaultCell()) {
        return;
    } else {
        this->fieldMap[changedCell[0] - 1][changedCell[1] - 1].setRealValue(changedCell[2]);
        return;
    }
}

void SudokuField::doNextStep() {
    this->printField();
    this->changeCell();
}

bool SudokuField::isEndGame() const {
    if (this->exit) return true;
    for (int i = 0; i < this->fieldMap.size(); i++) {
        for (int j = 0; j < this->fieldMap.size(); j++) {
            if (!fieldMap[i][j].isRight())
                return false;
        }
    }
    return true;
}

bool SudokuField::isExit() const {
    return exit;
}