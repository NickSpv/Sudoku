#include "SudokuField.h"

SudokuField::SudokuField() {
    this->exit = false;
}

void SudokuField::generateField(int n) {
    this->fieldMap = std::vector<std::vector<CellField >>(n, std::vector<CellField>(n, CellField(0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            this->fieldMap[i][j] = CellField((j + i * (int) pow(n, 0.5) + i / (int) pow(n, 0.5)) % n + 1);
        }
    }

    int sqrt_n = (int) pow(n, 0.5);

    std::default_random_engine gen(std::time(nullptr));

    if ((int) gen() % 2) this->transpose();
    for (int i = 0; i < (int) gen() % 40 + 20; i++) {
        this->swapCols((int) gen() % n, (int) gen() % n, true);
        this->swapRows((int) gen() % n, (int) gen() % n, true);
        int section = (int) (gen() % n) / sqrt_n * sqrt_n;
        this->swapCols(section + (int) gen() % sqrt_n, section + (int) gen() % sqrt_n, false);
        section = (int) (gen() % n) / sqrt_n * sqrt_n;
        this->swapRows(section + (int) gen() % sqrt_n, section + (int) gen() % sqrt_n, false);
    }

    std::uniform_int_distribution<int> dist_tmp(int(n * n * 0.6), int(n * n * 0.9));
    int countEmptyCel = dist_tmp(gen);

    std::uniform_int_distribution<int> dist_n(0, n - 1);
    for (int i = 0; i < countEmptyCel; i++) {
        this->fieldMap[dist_n(gen)][dist_n(gen)].hide();
    }
}

void SudokuField::printField() {
    this->exit = false;

    system("clear");
    std::cout << setSecondText << "Чтобы перейти в меню введите -1.\n" << setTableText;

    int n = (int) this->fieldMap.size();
    int rectSize = (int) pow((double) n, 0.5);
    std::string spaces;
    if (n == 4) {
        spaces = "                                 ";
    } else if (n == 9) {
        spaces = "                     ";
    } else if (n == 16) {
        spaces = "                                         ";
    }

    std::cout << spaces << "╔";
    for (int j = 0; j < n - 1; j++) std::cout << (((j + 1) % rectSize == 0) ? "════╦" : "════╤");
    std::cout << "════╗";

    for (int i = 0; i < n; i++) {
        std::cout << "\n" << spaces << "║ ";
        for (int j = 0; j < n; j++) {
            if (this->fieldMap[i][j].isDefaultCell()) {
                std::cout << setMainText << this->fieldMap[i][j].getRealValue() << setTableText;
            } else if (this->fieldMap[i][j].isVisible()) {
                std::cout << setSecondMainText << this->fieldMap[i][j].getRealValue() << setTableText;
            } else {
                std::cout << " ";
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
    std::cout << "Введите координаты и значение ячейки котрую вы хотите изменить.\n";

    try {
        std::string temp1, temp2, temp3;
        std::cout << "Строка: ";
        std::cin >> temp1;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        changedCell[0] = std::stoi(temp1);
        if (changedCell[0] == -1) {
            this->exit = true;
            return;
        }
        std::cout << "Столбец: ";
        std::cin >> temp2;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Значение: ";
        std::cin >> temp3;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        changedCell[1] = std::stoi(temp2);
        changedCell[2] = std::stoi(temp3);
    } catch (std::invalid_argument &err) {
        return;
    }

    int n = (int) this->fieldMap.size();
    if (changedCell[0] > n || changedCell[0] <= 0 || changedCell[1] > n || changedCell[1] <= 0 || changedCell[2] > n ||
        changedCell[2] <= 0) {
        return;
    }
    if (this->fieldMap[changedCell[0] - 1][changedCell[1] - 1].isDefaultCell()) {
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
            std::vector<int> check(this->fieldMap.size(), 0);
            int m = (int) pow(this->fieldMap.size(), 0.5);
            for (int k = 0; k < this->fieldMap.size(); k++) {
                if (this->fieldMap[i][k].isVisible() && this->fieldMap[k][j].isVisible()) {
                    check[this->fieldMap[i][k].getRealValue() - 1]++;
                    check[this->fieldMap[k][j].getRealValue() - 1]++;
                } else return false;
                std::cout << this->fieldMap[i][k].getRealValue() << " "
                          << this->fieldMap[k][j].getRealValue() << "\n";
            }
            for (int k = i / m * m; k < i / m * m + m; k++) {
                for (int q = j / m * m; q < j / m * m + m; q++) {
                    if (fieldMap[k][q].isVisible())
                        check[fieldMap[k][q].getRealValue() - 1]++;
                    else return false;
                    std::cout << fieldMap[k][q].getRealValue() << "\n";
                }
            }
            for (auto k: check) {
                if (k != 3) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool SudokuField::isExit() const {
    return exit;
}

void SudokuField::swapCols(int l, int r, bool isTheWholeSection) {
    int n = (int) pow(this->fieldMap.size(), 0.5);
    if (isTheWholeSection) {
        l /= n;
        r /= n;
        for (int i = 0; i < n; i++) {
            for (auto &j: this->fieldMap) {
                std::swap(j[l * n + i], j[r * n + i]);
            }
        }
    } else {
        for (auto &i: this->fieldMap) {
            std::swap(i[l], i[r]);
        }
    }
}

void SudokuField::swapRows(int l, int r, bool isTheWholeSection) {
    int n = (int) pow(this->fieldMap.size(), 0.5);
    if (isTheWholeSection) {
        l /= n;
        r /= n;
        for (int i = 0; i < n; i++) std::swap(this->fieldMap[l * n + i], this->fieldMap[r * n + i]);
    } else {
        std::swap(this->fieldMap[l], this->fieldMap[r]);
    }
}

void SudokuField::transpose() {
    int n = (int) this->fieldMap.size();
    std::vector<std::vector<CellField>> temp(n, std::vector<CellField>(n, CellField(0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][i] = this->fieldMap[i][j];
        }
    }
    this->fieldMap = temp;
}

