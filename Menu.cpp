#include "Menu.h"

Menu::Menu() {
    menuElements = {
            "Начало игры",
            "Выход"
    };
    name = mainName;
}

int Menu::startMenu() {
    system("clear");

    std::cout << setTitleText << this->name << setMainText;
    for (unsigned i = 0; i < menuElements.size(); i++) {
        std::cout << i + 1 << ". " << menuElements[i] << '\n';
    }
    int action;
    std::cout << "\nВыберите действие: ";
    std::cin >> action;
    while (action < 1 || action > menuElements.size()) {
        std::cout << "Incorrect number!!!\n";
        std::cout << "Выберите действие: ";
        std::cin >> action;
    }
    return action;
}