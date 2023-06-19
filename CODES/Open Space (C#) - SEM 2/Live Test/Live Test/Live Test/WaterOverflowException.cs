using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Live_Test
{
    //this exeception is thrown when the reservoir is overflowing
    public class WaterOverflowException : Exception
    {
        public WaterOverflowException(string message) : base(message) { }
    }
}
