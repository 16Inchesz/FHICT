using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Assignment_2A_SEM2
{
    internal class HalfContainer : Container
    {
        private int maxVolume = 40;
        private double volume;

        public HalfContainer(double volume, int serialNumber, string discription, string countryOfOrigin, double fee)
            : base(serialNumber, discription, countryOfOrigin, fee)
        {
            this.volume = volume;
        }
        public override double getFee(Container container)
        {
            if (volume > maxVolume)
            {
                MessageBox.Show("Weight is over max limit");
                return 0;
            }
            else
            {
                container.fee = volume * 19.37;
                return container.fee;
            }
        }
        public override string getInfoContainer(Container container)
        {
            HalfContainer halfContainer = (HalfContainer)container;
            string info = halfContainer.discription + " Fee:" + halfContainer.fee + " Country of Origin: " + halfContainer.countryOfOrigin + " Serial number: " + halfContainer.serialNumber + " Volume:" + halfContainer.volume;
            return info;
        }
    }
}
