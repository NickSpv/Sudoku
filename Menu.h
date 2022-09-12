#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "values.h"

class Menu {
public:
    Menu(); // заполнение вектора элементов меню
    int startMenu();


private:
    std::vector<std::string> menuElements;
    std::string name;

};