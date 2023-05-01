using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_2A_SEM2
{
    internal class Container
    {
        public double fee { get; set; }
        public int serialNumber { get; set; }
        public string discription { get; set; }
        public string countryOfOrigin { get; set; }

        public Container(int serialNumber,string discription, string countryOfOrigin, double fee) 
        {
            this.serialNumber = serialNumber;
            this.discription = discription;
            this.countryOfOrigin = countryOfOrigin;
            this.fee = fee;
        }
        public virtual double getFee(Container container)
        {
            return 0.00;
        }
        public virtual string getInfoContainer(Container container) 
        {
            string info = container.discription + " Fee:" + container.fee + " Country of Origin: "+ container.countryOfOrigin + " Serial number: " + container.serialNumber;
            return info;
        }
    }
}
