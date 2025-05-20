#include <iostream>
#include <string>

class String {
protected:
    std::string value;

public:
    // Конструктор з параметром
    String(const std::string& str) : value(str) {}

    // Метод для обчислення довжини рядка
    int length() const {
        return value.length();
    }

    // Метод для виведення рядка
    void print() const {
        std::cout << "Рядок: " << value << std::endl;
    }
};

class DigitString : public String {
public:
    // Конструктор з параметром
    DigitString(const std::string& str) : String(str) {}

    // Метод для видалення заданого символу
    void removeChar(char c) {
        value.erase(std::remove(value.begin(), value.end(), c), value.end());
    }

    // Метод отримання даних об’єкту
    std::string getValue() const {
        return value;
    }
};

int main() {
    // Створення об'єкта похідного класу
    DigitString ds("12345");
    ds.print();
    
    // Обчислення і виведення довжини
    std::cout << "Довжина рядка: " << ds.length() << std::endl;
    
    // Видалення символу '3' і повторний вивід
    ds.removeChar('3');
    ds.print();
    std::cout << "Довжина рядка після видалення: " << ds.length() << std::endl;

    return 0;
}
