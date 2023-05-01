using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_2A_SEM2
{
    internal class FullContainer : Container
    {
        private int maxKg = 20000;
        private double weight;
        private bool frige;

        public FullContainer(bool frige ,double weight, int serialNumber, string discription, string countryOfOrigin, double fee)
            : base(serialNumber, discription, countryOfOrigin, fee)
        {
            this.weight = weight;
            this.frige = frige;
        }
        public override double getFee(Container container)
        {
            if (weight > maxKg)
            {
                MessageBox.Show("Volume is over max limit");
                return 0;
            }
            else
            {
                if (!frige)
                {
                    container.fee = weight * 0.91;
                    return container.fee;
                }
                else
                {
                    container.fee = (weight * 0.91) * 1.08;
                    return container.fee;
                }
            }
        }
        public override string getInfoContainer(Container container)
        {
            FullContainer fullContainer = (FullContainer)container;
            string info = fullContainer.discription + " Fee:" + fullContainer.fee + " Country of Origin: " + fullContainer.countryOfOrigin + " Serial number: " + fullContainer.serialNumber + " Weight:" + fullContainer.weight;
            return info;
        }
    }      
}
