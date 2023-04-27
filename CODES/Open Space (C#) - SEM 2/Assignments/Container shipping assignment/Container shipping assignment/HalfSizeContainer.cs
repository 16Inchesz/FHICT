using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class HalfSizeContainer : Container
    {
        //instance variables
        private int volume;
        private const decimal FixedFeePerCubicMeter = 19.37m;

        //constructor
        public HalfSizeContainer(int serialNumber, string originCountry, string description, int volume)
            :base(serialNumber, originCountry, description)
        {
            this.volume = volume;
        }
        
        /// <summary>
        /// this method calculates the total fee
        /// </summary>
        /// <returns>total fee</returns>
        public override decimal GetTotalFee()
        {
            decimal totalFee = volume * FixedFeePerCubicMeter;
            return totalFee;
        }
    }
}
