using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class CustomExceptions : Exception
    {
        /// <summary>
        /// this class is for custom exceptions of unpredictable behaviour
        /// </summary>
        /// <param name="message"></param>
        public CustomExceptions(string message) : base(message) { }
    }
}
