using System;
using System.Collections.Generic;
using System.Linq;

class StudentTable
{
    private List<Student> students = new List<Student>();

    public void AddStudent(string firstName, string lastName, string middleName)
    {
        students.Add(new Student(firstName, lastName, middleName));
    }

    // Одновимірний індексатор
    public List<string> this[string column]
    {
        get
        {
            switch (column.ToLower())
            {
                case "ім'я":
                    return students.Select(s => s.FirstName).ToList();
                case "прізвище":
                    return students.Select(s => s.LastName).ToList();
                case "по батькові":
                    return students.Select(s => s.MiddleName).ToList();
                default:
                    throw new ArgumentException("Невідомий стовпець.");
            }
        }
    }

    // Властивість для підрахунку студентів із прізвищем "Нечай"
    public int NechaiCount
    {
        get { return students.Count(s => s.LastName == "Нечай"); }
    }
}

class Student
{
    public string FirstName { get; }
    public string LastName { get; }
    public string MiddleName { get; }

    public Student(string firstName, string lastName, string middleName)
    {
        FirstName = firstName;
        LastName = lastName;
        MiddleName = middleName;
    }
}

class Program
{
    static void Main()
    {
        StudentTable table = new StudentTable();
        table.AddStudent("Іван", "Нечай", "Петрович");
        table.AddStudent("Марія", "Шевченко", "Іванівна");
        table.AddStudent("Олександр", "Нечай", "Сергійович");

        Console.WriteLine("Список імен: " + string.Join(", ", table["ім'я"]));
        Console.WriteLine("Список прізвищ: " + string.Join(", ", table["прізвище"]));
        Console.WriteLine("Кількість студентів з прізвищем Нечай: " + table.NechaiCount);
    }
}
