using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public interface ILogicComponent
    {
        // Returns the state of an input pin.
        public bool GetInput(int pin);

        // Returns the state of an output in.
        public bool GetOutput(int pin);

        // Set the state of an input pin. 
        public void SetInput(int pin, bool value);

        // Connect an output of this component to an input of another component. 
        // Allows multiple connections from the same output to other output pins
        public void ConnectOutput(int outputPin, ILogicComponent other, int inputPin);
    }
}
