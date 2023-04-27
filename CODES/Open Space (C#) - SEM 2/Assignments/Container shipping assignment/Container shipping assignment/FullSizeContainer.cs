using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class FullSizeContainer : Container, IRefrigerated
    {
        private const decimal FixedFeePerKg = 0.91m;
        private const decimal RefrigerationFeePercentage = 0.08m;
        private int weight;

        //constructor
        public FullSizeContainer(int serialNumber, string originCountry, string description, int weight)
        : base(serialNumber, originCountry, description)
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
        /// If container is in need of refrigeration, this method will calculate the extra fee. 
        /// </summary>
        /// <returns>calculated refrigeration fee or 0</returns>
        public decimal GetRefrigerationFee()
        {
            if (!NeedsRefrigeration())
            {
                return 0m;
            }

            decimal totalFee = GetTotalFee();
            decimal refrigerationFee = totalFee * RefrigerationFeePercentage;
            return refrigerationFee;
        }

        /// <summary>
        /// this method calculates the fixed fee.
        /// </summary>
        /// <returns>fixed fee</returns>
        public decimal GetFixedFee()
        {
            decimal fixedFee = weight * FixedFeePerKg;
            return fixedFee;
        }

        /// <summary>
        /// this method calculates the total fee (include refrigeration costs)
        /// </summary>
        /// <returns>total fee</returns>
        public override decimal GetTotalFee()
        {
            decimal totalFee = GetFixedFee();
            totalFee += GetRefrigerationFee();
            return totalFee;
        }
    }

}
