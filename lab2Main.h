#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>

class Lines {
private:
    std::string line;
public:
    // Конструктор за замовчуванням
    Lines();
    // Конструктор з параметром
    Lines(const std::string& str);
    // Метод для обчислення довжини
    int length() const;
    // Метод для видалення символу '5'
    void removeFives();
    // Метод для отримання значення рядка
    const std::string& getValue() const;
};

#endif // MAIN_H