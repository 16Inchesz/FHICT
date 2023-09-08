using Live_Test;

VendingMachine vm = new VendingMachine();
vm.UseTheMachine();
Console.WriteLine("Machine initialized");
Console.WriteLine();
Console.WriteLine("Welcome to the Vending Machine!\n");
while (true)
    {
    try
    {
        Console.WriteLine("Products available: ");
        foreach (Product product in vm.products)
        {
            Console.WriteLine(product.ToString());
        }
        Console.WriteLine("=======================================================================");
        Console.WriteLine();
        Console.WriteLine();
        Console.WriteLine("Please select your drink:");
        Console.WriteLine("1. Coffee");
        Console.WriteLine("2. Tea");
        Console.WriteLine("3. Cooled Water");
        Console.WriteLine("4. Normal Water");
        Console.WriteLine("5. Chocolate drink");
        Console.Write("Enter your choice: ");
        vm.productName = Console.ReadLine();
        vm.state = VendingState.SELECT;
        vm.UseTheMachine();
        Console.WriteLine();
        if (vm.selectedProduct != null)
            Console.WriteLine("Ready, take your " + vm.selectedProduct.Name);
    }
    catch (ProductNotFoundException ex)
    {
        Console.WriteLine(ex.Message);
        continue;
    }
    Console.WriteLine();
    Console.WriteLine("=======================================================================");
    Console.WriteLine("Reservoir water content is: " + Product.waterReservoir);
    Console.WriteLine("=======================================================================");
    if (Product.waterReservoir < 200)
    {
        try
        {
            vm.FillReservoir(500f);
            Console.WriteLine("Reservoir water content is: " + Product.waterReservoir);
        }
        catch (WaterOverflowException e)
        {
            Console.WriteLine(e.Message);
        }
    }
    Console.WriteLine("Press any key to continue or q to quit");
    string key = Console.ReadLine();
    if (key == "q")
    {
        vm.state = VendingState.END;
        vm.UseTheMachine();
    }
    else
        Console.Clear();
}

