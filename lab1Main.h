#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>

class lines {
public:
    std::string text;
    // метод обчислення довжини рядка
    int numberSymbols();
    // метод вилучення з рядка символу '5'
    std::string textWithout5();
};

#endif // MAIN_H