using System;

//if variables added at start of program, you run into problems; ask why.


Console.Write("Enter your Weight in KGs: ");
double weight = Convert.ToDouble(Console.ReadLine());
Console.Write("Enter your height in CMs: ");
double height = Convert.ToDouble(Console.ReadLine());

double meters = height / 100;

double BMI = weight / (meters* meters);

Console.WriteLine("---------------------------------------");
Console.WriteLine("Your current BMI:{0} ", BMI);

if (BMI >= 0 && BMI < 18.5)
{
    Console.WriteLine("You are underweight");
} else if (BMI >= 18.5 && BMI < 25)
{
    Console.WriteLine("You are normal weight");
} else if (BMI >= 25 && BMI < 30)
{
    Console.WriteLine("You are overweight");
}
else
{
    Console.WriteLine("You are obese");
}

