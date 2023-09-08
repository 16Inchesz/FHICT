using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Live_Test
{
    public class VendingMachine
    {
        //variables
        public List<Product> products;
        public float waterReservoir;
        public VendingState state;
        public string productName;
        public IProduct selectedProduct;

        //constructor
        public VendingMachine()
        {
            Initialize();
        }

        /// <summary>
        /// this method initializes the vending machine with 
        /// </summary>
        private void Initialize()
        {
            // Initialize the vending machine with products available, setting the reservoir and  setting the state to the INIT state.
            products = new List<Product>
            {
                new Product("Coffee", 2.5f, 150),
                new Product("Tea", 2.0f, 200),
                new Product("Cooled Water", 1.0f, 100),
                new Product("Normal Water", 0.5f, 100),
            };

            Product.waterReservoir = 1000f;
            state = VendingState.INIT;
            selectedProduct = null;
        }

        /// <summary>
        /// this method acts as the state machine for this entire program.
        /// </summary>
        public void UseTheMachine()
        {
            switch (state)
            {
                case VendingState.INIT:
                    //initializating
                    break;

                case VendingState.SELECT:
                    //Products gets chosen in this state
                    FindSelectedProduct();
                    break;

                case VendingState.PREPARE:
                    //prepare the desired product.
                    PrepareSelectedProduct();
                    break;

                case VendingState.END:
                    //end program state
                    Environment.Exit(0);
                    break;

                default:
                    Console.WriteLine("Invalid state.");
                    break;
            }
        }

        /// <summary>
        /// thhis method checks to see if you have chosen a product that is available. An exception is thrown when it isn't.
        /// </summary>
        /// <exception cref="ProductNotFoundException"></exception>
        private void FindSelectedProduct()
        {
            //chat consultation
            if (!Enum.TryParse(productName, out VendingProduct selectedProductEnum))
            {
                throw new ProductNotFoundException("Invalid product selection.");
            }

            //used to check which product is chosen.
            switch (selectedProductEnum-1)
            {
                case VendingProduct.Coffee:
                    selectedProduct = products.FirstOrDefault(p => p.Name.Equals("Coffee", StringComparison.OrdinalIgnoreCase));
                    break;

                case VendingProduct.Tea:
                    selectedProduct = products.FirstOrDefault(p => p.Name.Equals("Tea", StringComparison.OrdinalIgnoreCase));
                    break;

                case VendingProduct.Water:
                    selectedProduct = products.FirstOrDefault(p => p.Name.Equals("Normal Water", StringComparison.OrdinalIgnoreCase));
                    break;

                case VendingProduct.CooledWater:
                    selectedProduct = products.FirstOrDefault(p => p.Name.Equals("Cooled Water", StringComparison.OrdinalIgnoreCase));
                    break;

                default:
                    throw new ProductNotFoundException("Selected product not found.");
            }

            state = VendingState.PREPARE;
        }

        /// <summary>
        /// this methods prepares the selected product it thorws an exception if reservoir is too low
        /// </summary>
        private void PrepareSelectedProduct()
        {
            if (selectedProduct.CheckWaterLevel())
            {
                try
                {
                    float waterNeeded = selectedProduct.AmountOfWater;
                    if (Product.waterReservoir < waterNeeded)
                    {
                        throw new OutOfWaterException("Not enough water in the reservoir.");
                    }

                    selectedProduct.Prepare();
                    Console.WriteLine($"Preparing {selectedProduct.Name}...");
                    Console.WriteLine("Drink is ready.");

                    // Subtract the amount of water needed from the reservoir
                    Product.waterReservoir -= waterNeeded;
                }
                catch (OutOfWaterException ex)
                {
                    Console.WriteLine(ex.Message);
                    Console.WriteLine("Please fill the reservoir to continue.");
                }
            }
            else
            {
                Console.WriteLine("Not enough water in the reservoir.");
                Console.WriteLine("Please fill the reservoir to continue.");
            }

            state = VendingState.SELECT;
        }

        /// <summary>
        /// this method sumpy fills the reservoir with an amount. if the amount overflwos an exception will be thrown.
        /// </summary>
        /// <param name="amount"></param>
        /// <exception cref="WaterOverflowException"></exception>
        public void FillReservoir(float amount)
        {
            if (Product.waterReservoir + amount > 1000)
            {
                throw new WaterOverflowException("Water reservoir is overflowing.");
            }

            Product.waterReservoir += amount;
        }
    }
}
