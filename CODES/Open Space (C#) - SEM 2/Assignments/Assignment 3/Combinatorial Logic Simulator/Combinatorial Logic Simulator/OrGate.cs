using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class OrGate : LogicGate
    {
        private List<bool> outputs;

        public OrGate()
        {
            inputs = new List<bool> { false, false };
            outputs = new List<bool> { false };
            connections = new List<Connection>();
        }

        public override bool GetOutput(int pin)
        {
            if(pin >= 0 && pin < outputs.Count)
            {
                CalculateOutput();
                return outputs[pin];
            }
            throw new InvalidPinException($"{pin} is not a valid output pin for {GetType().Name}"); 
        }

        private void CalculateOutput()
        {
            bool result = false;
            foreach (bool input in inputs)
            {
                result |= input;
            }
            outputs[0] = result;
        }
    }
}
