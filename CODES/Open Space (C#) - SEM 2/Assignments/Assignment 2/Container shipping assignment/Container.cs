using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public abstract class Container
    {
        //instance variables 
        public int serialNumber { get; set; }
        public string originCountry { get; set; }
        public string description { get; set; }
        public decimal price { get; set; }
        
        //constructor
        public Container(int serialNumber, string originCountry, string description, decimal price)
        {
            this.serialNumber = serialNumber;
            this.originCountry = originCountry;
            this.description = description;
            this.price = price;
        }

        /// <summary>
        /// abstract method so needs to be rewritten. Method get the total fee to be paid.
        /// </summary>
        /// <param name="container"></param>
        /// <returns></returns>
        public abstract decimal GetTotalFee(Container container);

        /// <summary>
        /// virutal method that can be rewritten. Method to get the information.
        /// </summary>
        /// <param name="container"></param>
        /// <returns></returns>
        public virtual string GetInfo(Container container)
        {
            string info = container.description + " price: " + container.price + " origin country: " + container.originCountry + " serial #: " + container.serialNumber;
            return info;
        }
    }
}
