using Combinatorial_Logic_Simulator;
using System;

class Program
{
    static void Main(string[] args)
    {
        // Create the logic gates
        AndGate andGate = new AndGate();
        OrGate orGate = new OrGate();
        NotGate notGate = new NotGate();
        XorGate xorGate = new XorGate();

        Console.WriteLine("Truth Table:");
        Console.WriteLine("A    B    AND    OR    NOT    XOR");

        // Iterate through all possible input combinations
        for (int a = 0; a <= 1; a++)
        {
            for (int b = 0; b <= 1; b++)
            {
                // Set the input values and check boolean value.
                andGate.SetInput(0, a == 1);
                andGate.SetInput(1, b == 1);

                orGate.SetInput(0, a == 1);
                orGate.SetInput(1, b == 1);

                notGate.SetInput(0, a == 1);

                xorGate.SetInput(0, a == 1);
                xorGate.SetInput(1, b == 1);

                // Print the current row of the truth table
                Console.WriteLine($"{a}    {b}    {andGate.GetOutput(0)}    {orGate.GetOutput(0)}    {notGate.GetOutput(0)}    {xorGate.GetOutput(0)}");
            }
        }
    }
}