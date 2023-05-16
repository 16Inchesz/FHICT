using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    //inherits from IlogicComponent interface.
    public abstract class LogicGate : ILogicComponent
    {
        //protected because these inputs are used by the inheriting classes but shouldn't be used by other classes.
        protected List<bool> inputs;
        protected List<Connection> connections;

        /// <summary>
        /// this method is used to get the input of the provided pin.
        /// </summary>
        /// <param name="pin"></param>
        /// <returns></returns>
        /// <exception cref="InvalidPinException"></exception>
        public bool GetInput(int pin)
        {
            if (pin >= 0 && pin < inputs.Count)
            {
                return inputs[pin];
            }
            throw new InvalidPinException($"{pin} is not a valid input pin for {GetType().Name}");
        }

        /// <summary>
        /// abstract method to get the value of the outputs.
        /// </summary>
        /// <param name="pin"></param>
        /// <returns></returns>
        public abstract bool GetOutput(int pin);

        /// <summary>
        /// method to Set the input for a specific pin, with the given value.
        /// </summary>
        /// <param name="pin"></param>
        /// <param name="value"></param>
        /// <exception cref="InvalidPinException"></exception>
        public void SetInput(int pin, bool value)
        {
            if (pin >= 0 && pin < inputs.Count)
            {
                inputs[pin] = value;
            }
            else
            {
                throw new InvalidPinException($"{pin} is not a valid input pin for {GetType().Name}");
            }
        }

        
        public void ConnectOutput(int outputPin, ILogicComponent other, int inputPin)
        {
            Connection connection = new Connection(this, outputPin, other, inputPin);
            connections.Add(connection);    
        }
    }
}
