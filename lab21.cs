using System;

class StringClass
{
    protected string value;

    // Конструктор з параметром
    public StringClass(string str)
    {
        value = str;
    }

    // Метод для обчислення довжини рядка
    public int Length()
    {
        return value.Length;
    }

    // Метод для виведення рядка
    public void Print()
    {
        Console.WriteLine("Рядок: " + value);
    }
}

class DigitString : StringClass
{
    // Конструктор з параметром
    public DigitString(string str) : base(str) { }

    // Метод для видалення заданого символу
    public void RemoveChar(char c)
    {
        value = value.Replace(c.ToString(), "");
    }

    // Метод отримання даних об’єкту
    public string GetValue()
    {
        return value;
    }
}

class Program
{
    static void Main()
    {
        // Створення об'єкта похідного класу
        DigitString ds = new DigitString("12345");
        ds.Print();

        // Обчислення і виведення довжини
        Console.WriteLine("Довжина рядка: " + ds.Length());

        // Видалення символу '3' і повторний вивід
        ds.RemoveChar('3');
        ds.Print();
        Console.WriteLine("Довжина рядка після видалення: " + ds.Length());
    }
}
