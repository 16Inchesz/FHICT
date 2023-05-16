using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class NotGate : LogicGate
    {
        //constructor.
        public NotGate()
        {
            inputs = new List<bool> { false };
            connections = new List<Connection>();
        }

        /// <summary>
        /// Gets the value of the output depending on the provided pin.
        /// </summary>
        /// <param name="pin"></param>
        /// <returns></returns>
        /// <exception cref="InvalidPinException"></exception>
        public override bool GetOutput(int pin)
        {
            if (pin == 0)
            {
                return !inputs[0];  //inverse of the input.
            }
            throw new InvalidPinException($"{pin} is not a valid output pin for {GetType().Name}");
        }
    }
}
