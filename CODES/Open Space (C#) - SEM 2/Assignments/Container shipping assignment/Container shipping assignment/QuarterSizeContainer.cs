using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class QuarterSizeContainer : Container
    {

        private const decimal FixedFee = 1692.72m;

        public QuarterSizeContainer(int serialNumber, string originCountry, string description)
            : base(serialNumber, originCountry, description)
        {
        }

        public override decimal GetTotalFee()
        {
            decimal totalFee = FixedFee;
            return totalFee;
        }
    }
}
