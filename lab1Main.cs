using System;

class Lines
{
    public string Text { get; set; }

    // Метод вычисления длины строки
    public int NumberSymbols()
    {
        int symbols = 0;
        foreach (char i in Text)
        {
            symbols++;
        }
        return symbols;
    }

    // Метод удаления символа '5' из строки
    public string TextWithout5()
    {
        string result = "";
        foreach (char i in Text)
        {
            if (i != '5')
            {
                result += i;
            }
        }
        return result;
    }
}

class Program
{
    static void Main()
    {
        Lines object1 = new Lines();
        object1.Text = Console.ReadLine();

        Console.WriteLine();
        Console.WriteLine(object1.NumberSymbols());
        Console.WriteLine(object1.TextWithout5());
    }
}