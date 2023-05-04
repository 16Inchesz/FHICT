using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class QuarterSizeContainer : Container
    {
        //instance variables
        private const decimal FixedFee = 1692.72m;

        //constructor
        public QuarterSizeContainer(int serialNumber, string originCountry, decimal price, string description)
            : base(serialNumber, originCountry, description, price)
        {
        }
        
        /// <summary>
        /// Method that gets the total fees to be paid.
        /// </summary>
        /// <param name="container"></param>
        /// <returns></returns>
        public override decimal GetTotalFee(Container container)
        {
            container.price = FixedFee;
            return container.price;
        }

        /// <summary>
        /// this method overrides then displays the container information
        /// </summary>
        /// <param name="container"></param>
        /// <returns></returns>
        public override string GetInfo(Container container)
        {
            QuarterSizeContainer quartersizecontainer = (QuarterSizeContainer)container;
            string info = quartersizecontainer.description + " Fee: " + quartersizecontainer.price + " Country of Origin: " + quartersizecontainer.originCountry + " Serial #: " + quartersizecontainer.serialNumber;
            return info;
        }
    }
}
