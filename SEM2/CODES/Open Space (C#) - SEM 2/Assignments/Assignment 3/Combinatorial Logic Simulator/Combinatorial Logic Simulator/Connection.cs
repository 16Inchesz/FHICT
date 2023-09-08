using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class Connection
    {
        //Instance variables used for establishing connections
        public int OutputPin { get; }
        public int InputPin { get; }

        //constructor
        public Connection(int outputPin, int inputPin)
        {
            OutputPin = outputPin;
            InputPin = inputPin;
        }
    }
}
