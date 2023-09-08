using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Live_Test
{
    public class Product : IProduct
    {
        public string Name { get; set; }
        public float Price { get; set; }
        public float AmountOfWater { get; set; }

        public static float waterReservoir;

        //constructor
        public Product(string name, float price, float amountOfWater)
        {
            Name = name;
            Price = price;
            AmountOfWater = amountOfWater;
        }

        /// <summary>
        /// this method prepares the desired drink
        /// </summary>
        public void Prepare()
        {
            //prep drink
        }

        /// <summary>
        /// this method checks the water level and see if it needs to be updated
        /// </summary>
        /// <returns></returns>
        public bool CheckWaterLevel()
        {
            //check water lvel
            return true;
        }

        /// <summary>
        /// this method resutrn the reservoir value
        /// </summary>
        /// <returns></returns>
        public static float GetWaterReservoir()
        {
            return waterReservoir;
        }

        /// <summary>
        /// this method resturn the product and price
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            string info = $"{Name} - ${Price}";
            return info;
        }
    }
}

