using Combinatorial_Logic_Simulator;
using System;

class Program
{
    static void Main(string[] args)
    {
        // Create instances of the logic gates and half adder.
        LogicGate andGate = new AndGate();
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
        Console.WriteLine("\nLogic Test Circuit:");
        Console.WriteLine("input_A      input_B      input_C      input_D      output");

        //create the inputs.
        bool A = false;
        bool B = true;
        bool C = false;
        bool D = false;

        try
        {
            //create instances of gates.
            AndGate andGate1 = new AndGate();
            AndGate andGate2 = new AndGate();
            OrGate orGate1 = new OrGate();
            NotGate notGate1 = new NotGate();

            //set inputs
            andGate1.SetInput(0, A);
            andGate1.SetInput(1, B);
            notGate1.SetInput(0, C);
            andGate2.SetInput(1, D);

            //----------------------Connections--------------------------------
            //connection between andGate1 and orGate
            Connection connection1 = new Connection(Convert.ToInt16(andGate1.GetOutput(0)), Convert.ToInt16(orGate1.GetInput(0)));
            orGate1.SetInput(connection1.InputPin, Convert.ToBoolean(connection1.OutputPin));

            //connection between notGate and orGate.
            Connection connection2 = new Connection(Convert.ToInt16(notGate1.GetOutput(0)), Convert.ToInt16(orGate1.GetInput(1)));
            orGate1.SetInput(connection2.InputPin, Convert.ToBoolean(connection2.OutputPin));

            //connection between orGate and andGate2
            Connection connection3 = new Connection(Convert.ToInt16(orGate1.GetOutput(0)), Convert.ToInt16(andGate2.GetInput(0)));
            andGate2.SetInput(connection3.InputPin, D);

            //results
            try
            {
                Console.WriteLine($"{A}        {B}        {C}        {D}        {andGate2.GetOutput(0)} ");
            }
            catch (InvalidPinException ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
        catch (InvalidPinException ex)
        {       
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
}