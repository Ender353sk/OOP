#include "main.h"

// Конструктор за замовчуванням
Lines::Lines() : line("") {}

// Конструктор з параметром
Lines::Lines(const std::string& str) : line(str) {}

// Метод для обчислення довжини
int Lines::length() const {
    return line.length();
}

// Метод для видалення символу '5'
void Lines::removeFives() {
    line.erase(std::remove(line.begin(), line.end(), '5'), line.end());
}

// Метод для отримання значення рядка
const std::string& Lines::getValue() const {
    return line;
}

int main() {
    // Створення об'єкта класу Lines
    Lines lineObj("1234556789");
    std::cout << "Рядок: " << lineObj.getValue() << std::endl;

    // Обчислення та виведення довжини рядка
    std::cout << "Довжина рядка: " << lineObj.length() << std::endl;

    // Видалення символу '5'
    lineObj.removeFives();
    std::cout << "Рядок після видалення '5': " << lineObj.getValue() << std::endl;

    // Обчислення та виведення нової довжини рядка
    std::cout << "Нова довжина рядка: " << lineObj.length() << std::endl;

    return 0;
}