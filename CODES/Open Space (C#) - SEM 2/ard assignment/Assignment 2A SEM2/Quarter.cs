using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_2A_SEM2
{
    internal class QuarterContainer : Container
    {
        public QuarterContainer(int serialNumber, string discription, string countryOfOrigin, double fee)
            : base(serialNumber, discription, countryOfOrigin, fee)
        {
        }
        public override double getFee(Container container)
        {
           container.fee = 1692.72;
           return container.fee;
        }
        public override string getInfoContainer(Container container)
        {
            QuarterContainer quarterContainer = (QuarterContainer)container;
            string info = quarterContainer.discription + " Fee:" + quarterContainer.fee + " Country of Origin: " + quarterContainer.countryOfOrigin + " Serial number: " + quarterContainer.serialNumber;
            return info;
        }
    }
}

