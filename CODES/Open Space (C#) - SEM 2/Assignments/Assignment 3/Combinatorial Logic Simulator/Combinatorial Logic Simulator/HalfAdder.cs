using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Combinatorial_Logic_Simulator
{
    public class HalfAdder : ILogicComponent
    {
        //composition: make instances of these classes without directly inheriting.
        private LogicGate andGate;
        private LogicGate xorGate;

        //constructor
        public HalfAdder()
        {
            //create instances of
            andGate = new AndGate();
            xorGate = new XorGate();
        }

        /// <summary>
        /// Gets the output of all the sums using the XorGate.
        /// </summary>
        /// <returns></returns>
        public bool GetSum()
        {
            return xorGate.GetOutput(0);
        }

        /// <summary>
        /// gets the output of all the carry's using the AndGate
        /// </summary>
        /// <returns></returns>
        public bool GetCarry()
        {
            return andGate.GetOutput(0);
        }

        /// <summary>
        /// method to set the input bool value to an inputpin of a specific gate.
        /// </summary>
        /// <param name="valueA"></param>
        /// <param name="valueB"></param>
        public void SetInput(bool valueA, bool valueB)
        {
            andGate.SetInput(0, valueA);
            andGate.SetInput(1, valueB);
            xorGate.SetInput(0, valueA);
            xorGate.SetInput(1, valueB);
        }

        /// <summary>
        /// this method is used to get the input of the provided pin.
        /// </summary>
        /// <param name="pin"></param>
        /// <returns></returns>
        /// <exception cref="InvalidPinException"></exception>
        public bool GetInput(int pin)
        {
            if (pin == 0)
            {
                return andGate.GetInput(0);
            }
            else if (pin == 1)
            {
                return xorGate.GetInput(1);
            }
            throw new InvalidPinException($"{pin} is not a valid input pin for {GetType().Name}");
        }

        /// <summary>
        /// method to get the value of the different outputs.
        /// </summary>
        /// <param name="pin"></param>
        /// <returns></returns>
        /// <exception cref="InvalidPinException"></exception>
        public bool GetOutput(int pin)
        {
            if (pin == 0)
            {
                return xorGate.GetOutput(0);
            }
            else if(pin == 1)
            {
                return andGate.GetOutput(0);
            }
            throw new InvalidPinException($"{pin} is not a valid output pin for {GetType().Name}");
        }

        /// <summary>
        /// method to Set the input for a specific pin, with the given value.
        /// </summary>
        /// <param name="pin"></param>
        /// <param name="value"></param>
        /// <exception cref="InvalidPinException"></exception>
        public void SetInput(int pin, bool value)
        {
            if (pin == 0)
            {
                xorGate.SetInput(0, value);
            }
            else if (pin == 1)
            {
                xorGate.SetInput(1, value);
            }
            else
            {
                throw new InvalidPinException($"{pin} is not a valid input pin for {GetType().Name}");
            }
        }

        /// <summary>
        /// method used to connect components output with another components input.
        /// </summary>
        /// <param name="outputPin"></param>
        /// <param name="other"></param>
        /// <param name="inputPin"></param>
        /// <exception cref="NotImplementedException"></exception>
        public void ConnectOutput(int outputPin, ILogicComponent other, int inputPin)
        {
            throw new NotImplementedException("ConnectOutput method is not implemented for HalfAdder.");
        }
    }
}
