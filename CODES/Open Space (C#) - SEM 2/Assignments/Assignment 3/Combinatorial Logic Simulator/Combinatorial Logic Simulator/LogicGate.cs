using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public abstract class LogicGate : ILogicComponent
    {
        protected List<bool> inputs;
        protected List<Connection> connections;

        public bool GetInput(int pin)
        {
            if (pin >= 0 && pin < inputs.Count)
            {
                return inputs[pin];
            }
            throw new InvalidPinException($"{pin} is not a valid input pin for {GetType().Name}");
        }

        public abstract bool GetOutput(int pin);

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
