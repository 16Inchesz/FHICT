using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public abstract class Container
    {
        public int serialNumber { get; set; }
        public string originCountry { get; set; }
        public string description { get; set; }
        public decimal price { get; set; }
        
        public Container(int serialNumber, string originCountry, string description, decimal price)
        {
            this.serialNumber = serialNumber;
            this.originCountry = originCountry;
            this.description = description;
            this.price = price;
        }

        public abstract decimal GetTotalFee(Container container);

        public virtual string GetInfo(Container container)
        {
            string info = container.description + " price:" + container.price + " origin country:" + container.originCountry + " serial #:" + container.serialNumber;
            return info;
        }
    }
}
