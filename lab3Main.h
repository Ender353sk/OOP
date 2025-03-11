#ifndef MAIN_H
#define MAIN_H

#include <iostream>
using namespace std;

class Rectangle {
private:
    double x1, y1, x2, y2; // Координати вершин

public:
    // Конструктор за умовчанням
    Rectangle();

    // Конструктор з параметрами
    Rectangle(double x1, double y1, double x2, double y2);

    // Конструктор копіювання
    Rectangle(const Rectangle& rect);

    // Метод обчислення площі
    double area() const;

    // Метод обчислення периметра
    double perimeter() const;

    // Методи отримання даних прямокутника
    void getCoordinates() const;

    // Перевантаження оператора вирахування
    Rectangle operator-(const Rectangle& rect) const;

    // Перевантаження оператора ділення
    Rectangle operator/(double value) const;
};

#endif