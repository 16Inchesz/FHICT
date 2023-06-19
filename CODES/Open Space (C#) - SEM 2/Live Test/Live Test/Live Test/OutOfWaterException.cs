using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Live_Test
{
    /// <summary>
    /// this exeception is thrown when the reservoir is out of water.
    /// </summary>
    public class OutOfWaterException : Exception
    {
        public OutOfWaterException(string message) : base(message) { }
    }
}
