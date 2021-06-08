using System;
namespace Add_Num
{
    class Program
    {
        static void Main(string[] args)
        {
            double num1, num2;
            Console.WriteLine("Enter the numbers:");
            string n1 = Console.ReadLine(); // Readline() method returns string type
            string n2 = Console.ReadLine();
            double.TryParse(n1, out num1);
            double.TryParse(n2, out num2);
            double res = num1 + num2;
            Console.WriteLine(num1+num2);
            Console.Read(); // Read() accepts only single character
        }
    }
}

