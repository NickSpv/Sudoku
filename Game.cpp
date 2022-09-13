#include "Game.h"

Game::Game() {
    this->isEndGame = false;
}

void Game::startGame() {
    while (!isEndGame) {
        switch (this->menu.startMenu()) {
            case 1:
                this->sudokuField.generateField(4);
                break;
            case 2:
                this->sudokuField.generateField(9);
                break;
            case 3:
                this->sudokuField.generateField(16);
                break;
            case 4:
                return;
        }
        while (true) {
            this->sudokuField.doNextStep();
            if (this->sudokuField.isEndGame()) {
                if (!this->sudokuField.isExit()){
                    this->gameWin();
                }
                break;
            }
        }
    }
}

void Game::gameWin() {
    system("clear");
    std::cout << youWin;
    getchar();
    this->isEndGame = true;
}
