using System;
using System.Collections.Generic;

class ExpressionCalculator
{
    private double a, b, c;

    // Конструктор за замовчуванням
    public ExpressionCalculator()
    {
        a = 0;
        b = 0;
        c = 0;
    }

    // Конструктор з параметрами
    public ExpressionCalculator(double a_val, double b_val, double c_val)
    {
        a = a_val;
        b = b_val;
        c = c_val;
    }

    // Методи встановлення значень змінних
    public void SetValues(double a_val, double b_val, double c_val)
    {
        a = a_val;
        b = b_val;
        c = c_val;
    }

    // Метод обчислення виразу
    public double CalculateExpression()
    {
        if (b <= 1)
        {
            Console.WriteLine("Помилка: логарифм b-1 невизначений для b <= 1");
            return double.NaN;
        }
        return (8 * Math.Log10(b - 1) - c) / (a * 2 + b / c);
    }

    // Метод отримання значень змінних
    public void PrintValues()
    {
        Console.WriteLine($"a = {a}, b = {b}, c = {c}");
    }
}

class Program
{
    static void Main()
    {
        // Створюємо список об'єктів
        List<ExpressionCalculator> expressions = new List<ExpressionCalculator>
        {
            new ExpressionCalculator(2, 10, 4),
            new ExpressionCalculator(3, 15, 5),
            new ExpressionCalculator(1, 5, 2)
        };

        // Обчислення виразу для кожного об'єкта та вивід результату
        foreach (var expr in expressions)
        {
            expr.PrintValues();
            Console.WriteLine($"Результат обчислення: {expr.CalculateExpression()}\n");
        }
    }
}
