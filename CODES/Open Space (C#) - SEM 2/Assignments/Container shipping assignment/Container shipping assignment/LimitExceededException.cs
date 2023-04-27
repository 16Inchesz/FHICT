using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class LimitExceededException : Exception
    {
        public LimitExceededException(string message) : base(message)
        {
        }
    }
}
