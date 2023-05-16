using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class InvalidPinException : Exception
    {
        /// <summary>
        /// this class represents the custom exception thrown when the I/O pins are not corrects
        /// </summary>
        /// <param name="message"></param>
        public InvalidPinException(string message) : base(message){ }
    }
}
