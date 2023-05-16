using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class ConnectionAlreadyCreated : Exception
    {
        /// <summary>
        /// This class represents the custom exception thrown when a connection from an output to an input already exists.
        /// </summary>
        /// <param name="message">The error message.</param>
        public ConnectionAlreadyCreated(string message) : base(message) { }
    }
}
