using System;

public class Rectangle
{
    private double x1, y1, x2, y2; // Координати вершин

    // Конструктор за замовчуванням
    public Rectangle()
    {
        x1 = 0;
        y1 = 0;
        x2 = 1;
        y2 = 1;
    }

    // Конструктор з параметрами
    public Rectangle(double x1, double y1, double x2, double y2)
    {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    // Конструктор копіювання
    public Rectangle(Rectangle rect)
    {
        x1 = rect.x1;
        y1 = rect.y1;
        x2 = rect.x2;
        y2 = rect.y2;
    }

    // Метод обчислення площі
    public double Area()
    {
        return Math.Abs((x2 - x1) * (y2 - y1));
    }

    // Метод обчислення периметру
    public double Perimeter()
    {
        return 2 * (Math.Abs(x2 - x1) + Math.Abs(y2 - y1));
    }

    // Метод отримання даних прямокутника
    public void GetCoordinates()
    {
        Console.WriteLine($"Вершина 1: ({x1}, {y1}), Вершина 2: ({x2}, {y2})");
    }

    // Перевантаження оператора віднімання
    public static Rectangle operator -(Rectangle rect1, Rectangle rect2)
    {
        return new Rectangle(rect1.x1 - rect2.x1, rect1.y1 - rect2.y1, rect1.x2 - rect2.x2, rect1.y2 - rect2.y2);
    }

    // Перевантаження оператора ділення
    public static Rectangle operator /(Rectangle rect, double value)
    {
        return new Rectangle(rect.x1 / value, rect.y1 / value, rect.x2 / value, rect.y2 / value);
    }
}

public class Program
{
    public static void Main()
    {
        // Створення об'єктів Q1, Q2, Q3 з використанням різних конструкторів
        Rectangle Q1 = new Rectangle();
        Rectangle Q2 = new Rectangle(2, 2, 4, 4);
        Rectangle Q3 = new Rectangle(Q2);

        // "Зменшення" об'єкта Q2 в 2 рази
        Q2 = Q2 / 2;

        // "Віднімання" з об'єкта Q3 об'єкта Q2 і результат "поміщаємо" в об'єкт Q1
        Q1 = Q3 - Q2;

        // Виведення результатів на екран
        Console.WriteLine("Q1: ");
        Q1.GetCoordinates();
        Console.WriteLine($"Площа Q1: {Q1.Area()}, Периметр Q1: {Q1.Perimeter()}");
        Console.WriteLine("Q2: ");
        Q2.GetCoordinates();
        Console.WriteLine($"Площа Q2: {Q2.Area()}, Периметр Q2: {Q2.Perimeter()}");
        Console.WriteLine("Q3: ");
        Q3.GetCoordinates();
        Console.WriteLine($"Площа Q3: {Q3.Area()}, Периметр Q3: {Q3.Perimeter()}");
    }
}