using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class FullSizeContainer : Container, IRefrigerated
    {
        //instance variables
        private const decimal FixedFeePerKg = 0.91m;
        private const decimal RefrigerationFeePercentage = 1.08m;
        private const int MaxPossibleWeight = 20000;
        private int weight;

        //constructor
        public FullSizeContainer(int serialNumber, string originCountry, string description, decimal price, int weight)
        : base(serialNumber, originCountry, description, price)
        {
            this.weight = weight;
        }

        /// <summary>
        /// this method is implemented to check if a container is in need of refrigeration or not.
        /// </summary>
        /// <returns>boolean result true if yes and false if not</returns>
        public bool NeedsRefrigeration()
        {
            return true;
        }

        /// <summary>
        /// this method calculates the fixed fee.
        /// </summary>
        /// <returns>fixed fee</returns>
       
        public override decimal GetTotalFee(Container container)
        {
            if (weight >= MaxPossibleWeight)
            {
                MessageBox.Show("Weight exceeded");
                return 0;
            }
            else
            {
                if (!NeedsRefrigeration())
                {
                    container.price = weight * FixedFeePerKg;
                    return container.price;
                } else
                {
                    container.price = (weight * FixedFeePerKg) * RefrigerationFeePercentage;
                    return container.price;
                }
            }
        }

        /// <summary>
        /// this method overrides then displays the container information
        /// </summary>
        /// <param name="container"></param>
        /// <returns></returns>
        public override string GetInfo(Container container)
        {
            FullSizeContainer fullsizecontainer = (FullSizeContainer)container;
            string info = fullsizecontainer.description + " Fee:" + fullsizecontainer.price + " Country of Origin: " + fullsizecontainer.originCountry + " Serial number: " + fullsizecontainer.serialNumber + " Weight:" + fullsizecontainer.weight;
            return info;
        }

    }

}
