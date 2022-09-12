#include "Game.h"

Game::Game(int size_) {
    this->size = size_;
    this->isEndGame = false;
}

void Game::startGame() {
    while (!isEndGame) {
        switch (this->menu.startMenu()) {
            case 1:
                this->sudokuField.generateField(this->size);
                while (true) {
                    this->sudokuField.doNextStep();
                    if (this->sudokuField.isEndGame()) {
                        this->gameWin();
                        break;
                    }
                }
                break;
            case 2:
                return;
        }
    }
}

void Game::gameWin() {
    system("clear");
    std::cout << "You win!!!";
    getchar();
    this->isEndGame = true;
}
