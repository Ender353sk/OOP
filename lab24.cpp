#include <iostream>
#include <cmath>
#include <vector>

class ExpressionCalculator {
private:
    double a, b, c;

public:
    // Конструктор за замовчуванням
    ExpressionCalculator() : a(0), b(0), c(0) {}

    // Конструктор з параметрами
    ExpressionCalculator(double a_val, double b_val, double c_val) : a(a_val), b(b_val), c(c_val) {}

    // Методи встановлення значень змінних
    void setValues(double a_val, double b_val, double c_val) {
        a = a_val;
        b = b_val;
        c = c_val;
    }

    // Метод обчислення виразу
    double calculateExpression() const {
        if (b <= 1) {
            std::cerr << "Помилка: логарифм b-1 невизначений для b <= 1\n";
            return NAN;
        }
        return (8 * log10(b - 1) - c) / (a * 2 + b / c);
    }

    // Метод отримання значень змінних
    void printValues() const {
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";
    }
};

int main() {
    // Створюємо масив об'єктів
    std::vector<ExpressionCalculator> expressions = {
        ExpressionCalculator(2, 10, 4),
        ExpressionCalculator(3, 15, 5),
        ExpressionCalculator(1, 5, 2)
    };

    // Обчислення виразу для кожного об'єкта та вивід результату
    for (const auto& expr : expressions) {
        expr.printValues();
        std::cout << "Результат обчислення: " << expr.calculateExpression() << "\n\n";
    }

    return 0;
}
