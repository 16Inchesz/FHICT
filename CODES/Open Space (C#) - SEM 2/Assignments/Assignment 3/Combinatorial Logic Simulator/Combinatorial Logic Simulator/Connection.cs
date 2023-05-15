using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class Connection
    {
        public ILogicComponent OutputComponent { get; }
        public int OutputPin { get; }
        public ILogicComponent InputComponent { get; }
        public int InputPin { get; }

        public Connection(ILogicComponent outputComponent, int outputPin, ILogicComponent inputComponent, int inputPin)
        {
            OutputComponent = outputComponent;
            OutputPin = outputPin;
            InputComponent = inputComponent;
            InputPin = inputPin;
        }
    }
}
