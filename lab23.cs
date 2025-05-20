using System;
using System.Collections.Generic;
using System.Linq;

public interface IDigitProcessor
{
    double GetDigitPercentage();
    int GetTotalCharacterCount();
}

// Клас-рядок
public class StringElement
{
    private string data;

    public StringElement(string str)
    {
        data = str;
    }

    public string GetString() => data;

    public int Length() => data.Length;

    public bool HasDigits() => data.Any(char.IsDigit);

    public int CountDigits() => data.Count(char.IsDigit);
}

// Клас-контейнер
public class TextContainer : IDigitProcessor
{
    private List<StringElement> textElements = new List<StringElement>();

    public void AddString(string str) => textElements.Add(new StringElement(str));

    public void RemoveString(string str)
    {
        textElements.RemoveAll(elem => elem.GetString() == str);
    }

    public void ClearText() => textElements.Clear();

    public string GetLargestString()
    {
        return textElements.Count == 0 ? "" : textElements.OrderByDescending(e => e.Length()).First().GetString();
    }

    public double GetDigitPercentage()
    {
        int totalChars = GetTotalCharacterCount();
        if (totalChars == 0) return 0.0;

        int digitCount = textElements.Sum(elem => elem.CountDigits());

        return (double)digitCount / totalChars * 100.0;
    }

    public int GetTotalCharacterCount() => textElements.Sum(elem => elem.Length());

    public void PrintText()
    {
        foreach (var elem in textElements)
        {
            Console.WriteLine(elem.GetString());
        }
    }
}

// Тестування
public class Program
{
    public static void Main()
    {
        TextContainer text = new TextContainer();
        text.AddString("Hello123");
        text.AddString("Programming");
        text.AddString("C# is fun!");
        text.AddString("2025");

        Console.WriteLine("Збережений текст:");
        text.PrintText();
        
        Console.WriteLine($"\nНайбільший рядок: {text.GetLargestString()}");
        Console.WriteLine($"Відсоток цифр у тексті: {text.GetDigitPercentage()}%");
        Console.WriteLine($"Загальна кількість символів: {text.GetTotalCharacterCount()}");

        text.RemoveString("2025");
        Console.WriteLine("\nПісля видалення '2025':");
        text.PrintText();

        text.ClearText();
        Console.WriteLine("\nПісля очищення тексту:");
        text.PrintText();
    }
}
