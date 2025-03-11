using System;

public class Lines
{
    private string line;

    // Конструктор за замовчуванням
    public Lines()
    {
        line = "";
    }

    // Конструктор з параметром
    public Lines(string str)
    {
        line = str;
    }

    // Метод для обчислення довжини
    public int Length()
    {
        return line.Length;
    }

    // Метод для видалення символу '5'
    public void RemoveFives()
    {
        line = line.Replace("5", "");
    }

    // Метод для отримання значення рядка
    public string GetValue()
    {
        return line;
    }
}

class Program
{
    static void Main()
    {
        // Створення об'єкта класу Lines
        Lines lineObj = new Lines("1234556789");
        Console.WriteLine("Рядок: " + lineObj.GetValue());

        // Обчислення та виведення довжини рядка
        Console.WriteLine("Довжина рядка: " + lineObj.Length());

        // Видалення символу '5'
        lineObj.RemoveFives();
        Console.WriteLine("Рядок після видалення '5': " + lineObj.GetValue());

        // Обчислення та виведення нової довжини рядка
        Console.WriteLine("Нова довжина рядка: " + lineObj.Length());
    }
}