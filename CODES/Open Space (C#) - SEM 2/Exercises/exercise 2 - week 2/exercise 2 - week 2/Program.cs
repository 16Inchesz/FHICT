// See https://aka.ms/new-console-template for more information

Console.WriteLine("Please input value in inches");

double inches = Convert.ToInt32(Console.ReadLine());
double conversion = 2.54; 
double centimeters = inches * conversion;

Console.WriteLine(inches + " inches is equal to: " + centimeters + "CMs.");
