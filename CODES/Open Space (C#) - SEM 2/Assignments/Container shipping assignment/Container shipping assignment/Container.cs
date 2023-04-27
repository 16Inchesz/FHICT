using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public abstract class Container
    {
        private int serialNumber;
        private string originCountry;
        private string description;

        public Container(int serialNumber, string originCountry, string description)
        {
            this.serialNumber = serialNumber;
            this.originCountry = originCountry;
            this.description = description;
        }

        public int getSerialNumber() { return serialNumber; }

        public string GetOriginCountry(){ return originCountry; }

        public string GetDescription(){ return description; }

        public virtual double GetWeight()
        {
            return 0.0;
        }

        public virtual double GetVolume()
        {
            return 0.0;
        }

        public abstract decimal GetTotalFee();
    }
}
