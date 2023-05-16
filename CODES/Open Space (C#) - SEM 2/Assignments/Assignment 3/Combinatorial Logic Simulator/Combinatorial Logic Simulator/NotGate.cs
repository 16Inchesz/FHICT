using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class NotGate : LogicGate
    {
        public NotGate()
        {
            inputs = new List<bool> { false };
            connections = new List<Connection>();
        }

        public override bool GetOutput(int pin)
        {
            if (pin == 0)
            {
                return !inputs[0];
            }
            throw new InvalidPinException($"{pin} is not a valid output pin for {GetType().Name}");
        }
    }
}
