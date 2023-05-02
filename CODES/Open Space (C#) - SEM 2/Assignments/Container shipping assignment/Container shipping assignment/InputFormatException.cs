using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    //input exception
    public class InputFormatException : Exception
    {
        public InputFormatException(string message) : base(message)
        {
        }
    }
}
