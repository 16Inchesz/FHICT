using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class XorGate : LogicGate
    {
        //list of outputs.
        private List<bool> outputs;

        //constructor.
        public XorGate()
        {
            inputs = new List<bool> { false, false };
            outputs = new List<bool> { false };
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
            if (pin >= 0 && pin < outputs.Count)
            {
                CalculateOutput();
                return outputs[pin];
            }
            throw new InvalidPinException($"{pin} is not a valid output pin for {GetType().Name}");
        }

        /// <summary>
        /// method to calculate the boolean value of the outputs.
        /// </summary>
        private void CalculateOutput()
        {
            bool result = inputs[0] ^ inputs[1];    //result compares the two outputs with an XOR(^) operation.
            outputs[0] = result;    //Update the output value.
        }
    }
}
