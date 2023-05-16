using Combinatorial_Logic_Simulator;
using System;

class Program
{
    static void Main(string[] args)
    {
        // Create instances of the logic gates and half adder.
        AndGate andGate = new AndGate();
        OrGate orGate = new OrGate();
        NotGate notGate = new NotGate();
        XorGate xorGate = new XorGate();
        HalfAdder halfAdder = new HalfAdder();

        Console.WriteLine("Truth Table:");
        Console.WriteLine("A    B    AND    OR    NOT    XOR");

        // Iterate through all possible input combinations
        for (int input0 = 0; input0 <= 1; input0++)
        {
            for (int input1 = 0; input1 <= 1; input1++)
            {
                try
                {
                    // Set the input values and check boolean value.
                    andGate.SetInput(0, input0 == 1);
                    andGate.SetInput(1, input1 == 1);

                    orGate.SetInput(0, input0 == 1);
                    orGate.SetInput(1, input1 == 1);

                    notGate.SetInput(0, input0 == 1);

                    xorGate.SetInput(0, input0 == 1);
                    xorGate.SetInput(1, input1 == 1);

                    try
                    {
                        // Print the current row of the truth table
                        Console.WriteLine($"{input0}    {input1}    {andGate.GetOutput(0)}    {orGate.GetOutput(0)}    {notGate.GetOutput(0)}    {xorGate.GetOutput(0)}");
                    }
                    catch (InvalidPinException ex)
                    {
                        Console.WriteLine($"Error: {ex.Message}");  //exception in case of wrong output pin.
                    }
                }
                catch (InvalidPinException ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");  //exception in case of wrong input pin.
                }

            }
        }
        Console.WriteLine("\nHalf Adder:");
        Console.WriteLine("A    B    Sum    Carry");


        // Iterate through all possible input combinations
        for (int input0 = 0; input0 <= 1; input0++)
        {
            for (int input1 = 0; input1 <= 1; input1++)
            {
                try
                {
                    // Set the input values
                    halfAdder.SetInput(input0 == 1, input1 == 1);

                    try
                    {
                        // Print the current row of the half adder truth table
                        Console.WriteLine($"{input0}    {input1}    {halfAdder.GetSum()}    {halfAdder.GetCarry()}");
                    }
                    catch (InvalidPinException ex)
                    {
                        Console.WriteLine($"Error: {ex.Message}");  //exception in case of wrong output pin.
                    }
                }
                catch (InvalidPinException ex)
                {
                    Console.WriteLine($"Error: {ex.Message}");  //exception in case of wrong input pin.
                }
            }
        }
    }
}