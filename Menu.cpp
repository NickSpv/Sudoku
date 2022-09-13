#include "Menu.h"

Menu::Menu() {
    menuElements = {
            "Простой уровень: 2×2󠁢󠁳󠁣󠁴",
            "Нормальный уровень: 3×3󠁢󠁳󠁣󠁴",
            "Сложный уровень: 4×4 (необходимо развернуть консоль на весь экран)",
            "Выход"
    };
    name = mainName;
}

int Menu::startMenu() {
    system("clear");

    std::cout << setTitleText << this->name << setMainText;
    for (unsigned i = 0; i < menuElements.size(); i++) {
        std::cout << " " << i + 1 << ". " << menuElements[i] << '\n';
    }

    std::string action_str;
    int action;

    bool continueFlag;
    do {
        continueFlag = true;
        std::cout << "\n Выберите действие: ";
        std::cin >> action_str;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        try {
            action = std::stoi(action_str);
        } catch (std::invalid_argument &err) {
            std::cout << " Некорректное число!!!\n";
            continueFlag = false;
        }
    } while (!continueFlag || action < 1 || action > menuElements.size());

    return action;
}
