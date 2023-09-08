using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Live_Test
{
    public class TemperatureControlledProduct : Product, ITemperatureControlledProduct
    {
        public int Temperature { get; set; }
        public bool IsHeated { get; set; }
        //constructor.
       public TemperatureControlledProduct(string name, float price, float amountOfWater)
            : base(name, price, amountOfWater)
       {

       }
    }
}
