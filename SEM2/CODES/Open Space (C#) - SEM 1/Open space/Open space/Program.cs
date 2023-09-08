
using System.Runtime.InteropServices;

public class Program
{
	public static void Main(string[] args)
	{
		int i;
		Console.Write("how many people are in the group: ");
		int m = Convert.ToInt32(Console.ReadLine());
		Console.WriteLine("---------------------------------");

        string[] names;
        names = new string[m];
		int[] age;
		age = new int[m];

		for(i = 0; i < names.Length; i++)
		{
			Console.Write("Please enter name of person: ");
			names[i] = Console.ReadLine();
			Console.Write("please enter age of person: ");
			age[i] = Convert.ToInt32(Console.ReadLine());
		}

        Console.WriteLine("---------------------------------");
        Console.WriteLine("You entered the following data:\n");
        for (i = 0; i < names.Length; i++)
		{
			Console.WriteLine("{0}, {1} Year(s) old.", names[i], age[i]);
		}
    }
}
