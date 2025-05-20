#include <iostream>
#include <cmath>

// Абстрактний базовий клас "Фігури"
class Figure {
public:
    // Чисто віртуальні функції для обчислення площі та периметра
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;

    // Віртуальний деструктор для коректного видалення похідних класів
    virtual ~Figure() {}
};

// Клас "Трапеція", успадковує "Фігури"
class Trapezoid : public Figure {
private:
    // Координати вершин трапеції
    double x1, y1, x2, y2, x3, y3, x4, y4;

    // Метод для обчислення відстані між двома точками
    double distance(double xA, double yA, double xB, double yB) const {
        return std::sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
    }

public:
    // Конструктор з параметрами
    Trapezoid(double _x1, double _y1, double _x2, double _y2, 
              double _x3, double _y3, double _x4, double _y4)
        : x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3), x4(_x4), y4(_y4) {}

    // Обчислення площі трапеції
    double getArea() const override {
        double base1 = distance(x1, y1, x2, y2);  // Верхня основа
        double base2 = distance(x3, y3, x4, y4);  // Нижня основа
        double height = std::fabs(y1 - y3);       // Висота (припускаємо, що y1 і y3 лежать на одній вертикалі)
        return 0.5 * (base1 + base2) * height;
    }

    // Обчислення периметра трапеції
    double getPerimeter() const override {
        return distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) +
               distance(x3, y3, x4, y4) + distance(x4, y4, x1, y1);
    }
};

// Клас "Коло", успадковує "Фігури"
class Circle : public Figure {
private:
    double radius;  // Радіус кола

public:
    // Конструктор з параметром
    Circle(double _radius) : radius(_radius) {}

    // Обчислення площі кола
    double getArea() const override {
        return M_PI * radius * radius;
    }

    // Обчислення периметра (довжини окружності)
    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }
};

int main() {
    // Масив покажчиків на об'єкти класів
    Figure* figures[2];

    // Створення об'єкта "Трапеція" з заданими координатами
    figures[0] = new Trapezoid(0, 0, 4, 0, 3, 2, 1, 2);

    // Створення об'єкта "Коло" з заданим радіусом
    figures[1] = new Circle(5);

    // Вивід площі та периметра кожного об'єкта
    for (int i = 0; i < 2; ++i) {
        std::cout << "Площа: " << figures[i]->getArea() << "\n";
        std::cout << "Периметр: " << figures[i]->getPerimeter() << "\n\n";
    }

    // Видалення об'єктів для уникнення витоків пам'яті
    delete figures[0];
    delete figures[1];

    return 0;
}
