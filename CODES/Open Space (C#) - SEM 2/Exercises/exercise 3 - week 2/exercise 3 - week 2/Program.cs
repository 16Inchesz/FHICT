// See https://aka.ms/new-console-template for more information

double inches = 0;
double convert_value = 2.54;
double centimeters = 0;
Console.WriteLine("input command");
string conversion = Console.ReadLine();
if (conversion == "/r")
{
    Console.WriteLine("Please input value in inches");
    inches = Convert.ToDouble(Console.ReadLine());
    centimeters = inches * convert_value;
    Console.WriteLine(inches + " inches is equal to: " + centimeters + "CMs.");
}
else if (conversion != "/r")
{
    Console.WriteLine("Please input value in centimeters");
    centimeters = Convert.ToDouble(Console.ReadLine());
    inches = centimeters / convert_value;
    Console.WriteLine(centimeters + "CMs is equal to: " + inches + " inches");

}
