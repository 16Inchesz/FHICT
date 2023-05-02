using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Permissions;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class HalfSizeContainer : Container
    {
        //instance variables
        private int volume;
        private const int MaxPossibleVolume = 40;
        private const decimal FixedFeePerCubicMeter = 19.37m;

        //constructor
        public HalfSizeContainer(int serialNumber, string originCountry, string description, decimal price, int volume)
            :base(serialNumber, originCountry, description, price)
        {
            this.volume = volume;
        }
        
        /// <summary>
        /// this method calculates the total fee to be paid.
        /// </summary>
        /// <returns>total fee</returns>
        public override decimal GetTotalFee(Container container)
        {
            if (volume >= MaxPossibleVolume)
            {
                MessageBox.Show("Volume exceeded");
                return 0;
            }else
            {
                container.price = volume * FixedFeePerCubicMeter;
                return container.price;
            }
        }

        /// <summary>
        /// this method overrides then displays the container information
        /// </summary>
        /// <param name="container"></param>
        /// <returns></returns>
        public override string GetInfo(Container container)
        {
            HalfSizeContainer halfsizecontainer = (HalfSizeContainer)container;
            string info = halfsizecontainer.description + " Fee: " + halfsizecontainer.price + " Country of Origin: " + halfsizecontainer.originCountry + " Serial #: " + halfsizecontainer.serialNumber + " Volume: " + halfsizecontainer.volume;
            return info;
        }
    }
}
