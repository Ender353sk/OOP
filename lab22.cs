using System;

abstract class Figure
{
    public abstract double GetArea();
    public abstract double GetPerimeter();
}

// Клас "Трапеція"
class Trapezoid : Figure
{
    private double x1, y1, x2, y2, x3, y3, x4, y4;

    private double Distance(double xA, double yA, double xB, double yB)
    {
        return Math.Sqrt((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA));
    }

    public Trapezoid(double x1, double y1, double x2, double y2, 
                     double x3, double y3, double x4, double y4)
    {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.x3 = x3;
        this.y3 = y3;
        this.x4 = x4;
        this.y4 = y4;
    }

    public override double GetArea()
    {
        double base1 = Distance(x1, y1, x2, y2);
        double base2 = Distance(x3, y3, x4, y4);
        double height = Math.Abs(y1 - y3);
        return 0.5 * (base1 + base2) * height;
    }

    public override double GetPerimeter()
    {
        return Distance(x1, y1, x2, y2) + Distance(x2, y2, x3, y3) +
               Distance(x3, y3, x4, y4) + Distance(x4, y4, x1, y1);
    }
}

// Клас "Коло"
class Circle : Figure
{
    private double radius;

    public Circle(double radius)
    {
        this.radius = radius;
    }

    public override double GetArea()
    {
        return Math.PI * radius * radius;
    }

    public override double GetPerimeter()
    {
        return 2 * Math.PI * radius;
    }
}

class Program
{
    static void Main()
    {
        Figure[] figures = new Figure[2];

        figures[0] = new Trapezoid(0, 0, 4, 0, 3, 2, 1, 2);
        figures[1] = new Circle(5);

        foreach (var figure in figures)
        {
            Console.WriteLine($"Площа: {figure.GetArea()}");
            Console.WriteLine($"Периметр: {figure.GetPerimeter()}\n");
        }
    }
}
