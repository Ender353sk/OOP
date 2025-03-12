#include <iostream>
using namespace std;

class Rectangle {
private:
    double x1, y1, x2, y2; // Координати вершин

public:
    // Конструктор за умовчанням
    Rectangle() : x1(0), y1(0), x2(1), y2(1) {}

    // Конструктор з параметрами
    Rectangle(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    // Конструктор копіювання
    Rectangle(const Rectangle& rect) : x1(rect.x1), y1(rect.y1), x2(rect.x2), y2(rect.y2) {}

    // Метод обчислення площі
    double area() const {
        return abs((x2 - x1) * (y2 - y1));
    }

    // Метод обчислення периметра
    double perimeter() const {
        return 2 * (abs(x2 - x1) + abs(y2 - y1));
    }

    // Методи отримання даних прямокутника
    void getCoordinates() const {
        cout << "Вершина 1: (" << x1 << ", " << y1 << "), Вершина 2: (" << x2 << ", " << y2 << ")" << endl;
    }

    // Перевантаження оператора вирахування
    Rectangle operator-(const Rectangle& rect) const {
        return Rectangle(x1 - rect.x1, y1 - rect.y1, x2 - rect.x2, y2 - rect.y2);
    }

    // Перевантаження оператора ділення
    Rectangle operator/(double value) const {
        return Rectangle(x1 / value, y1 / value, x2 / value, y2 / value);
    }
};

int main() {
    // Створення об'єктів Q1, Q2, Q3, використовуючи різні конструктори
    Rectangle Q1;
    Rectangle Q2(2, 2, 4, 4);
    Rectangle Q3(Q2);

    // "Зменшення" об'єкта Q2 у 2 рази
    Q2 = Q2 / 2;

    // "Вирахування" з об'єкта Q3 об'єкт Q2 і результат "поміщення" до об'єкта Q1
    Q1 = Q3 - Q2;

    // Виведення результатів на екран
    cout << "Q1: "; Q1.getCoordinates();
    cout << "Площа Q1: " << Q1.area() << ", Периметр Q1: " << Q1.perimeter() << endl;
    cout << "Q2: "; Q2.getCoordinates();
    cout << "Площа Q2: " << Q2.area() << ", Периметр Q2: " << Q2.perimeter() << endl;
    cout << "Q3: "; Q3.getCoordinates();
    cout << "Площа Q3: " << Q3.area() << ", Периметр Q3: " << Q3.perimeter() << endl;

    return 0;
}