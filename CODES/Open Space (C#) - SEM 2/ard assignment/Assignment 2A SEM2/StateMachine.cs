using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_2A_SEM2
{
    internal class StateMachine
    {
        private string response;
        private List<Container> Containers = new List<Container>();
        public enum State
        {
            WELCOME,
            TYPE,
            FRIDGE,
            WEIGHT,
            VOLUME,
            ACK,
            ERR,
        }
        public enum Type
        {
            Full,
            Half,
            Quarter
        }
        // Veriables
        Type type;
        int serialNumber = 0;
        double fee =0;

        //Veriables for FULL
        double weight = 0 ;
        //Veriables for HALF
        double volume = 0;
        bool Frige;
        State MachineState = State.WELCOME;
        public void SwitchState(string input, State state)
        {
            if (state != State.ERR)
            {
                if (state == State.WELCOME)
                {
                    if (input == null || input != "START")
                    {
                        MachineState = State.ERR;
                    }
                    response = "TYPE";
                    MachineState = State.TYPE;
                }

                if (state == State.TYPE)
                {
                    if (input == null)
                    {
                        MachineState = State.ERR;
                    }
                    else if (input == "FULL")
                    {
                        response = "FRIDGE";
                        type = Type.Full;
                        MachineState = State.FRIDGE;
                    }
                    else if (input == "HALF")
                    {
                        response = "VOLUME";
                        type = Type.Half;
                        MachineState = State.VOLUME;
                    }
                    else if (input == "QUARTER")
                    {
                        response = "ACK";
                        type = Type.Quarter;
                        MachineState = State.ACK;
                    }
                    else
                    {
                        MachineState = State.ERR;
                    }
                }
                if(state == State.FRIDGE)
                {
                    if (input == "YES")
                    {
                        Frige = true;
                        MachineState = State.WEIGHT;
                        response = "WEIGHT";
                    }
                    else if (input == "NO")
                    {
                        Frige = false;
                        MachineState = State.WEIGHT;
                        response = "WEIGHT";
                    }
                    else
                    {
                        response = "ERR";
                        MachineState = State.ERR;
                    }
                }
                if (state == State.WEIGHT) 
                {
                    if (Convert.ToInt32(input) > 20000)
                    {
                        MachineState = State.ERR;
                        response = "ERR";
                    }
                    else
                    {
                        weight = Convert.ToDouble(input);
                        MachineState = State.ACK;
                        response = "ACK";
                    }
                }
                if (state == State.VOLUME)
                {
                    if (input == null ||Convert.ToInt32(input) > 40 || Convert.ToInt32(input) < 0)
                    {
                        MachineState = State.ERR;
                        response = "ERR";
                    }
                    else
                    {
                        volume = Convert.ToDouble(input);
                        MachineState = State.ACK;
                        response = "ACK";
                    }
                }
                if (state == State.ACK)
                {
                    ResetState();
                    NewContainer(type);
                }
            }
        }
        public void NewContainer(Type type)
        {
            switch (type) 
            {
                case Type.Full:
                    {
                        string disciption = " A full sized container ";
                        string countryOfOrigin = " Netherlands ";
                        Container container = new FullContainer(Frige ,weight, serialNumber, disciption, countryOfOrigin, fee);
                        container.fee = container.getFee(container);
                        Containers.Add(container);
                        serialNumber++;
                        break;
                    }
                case Type.Half:
                    {
                        string disciption = " A half sized container ";
                        string countryOfOrigin = " Netherlands ";
                        Container container = new HalfContainer(volume, serialNumber, disciption, countryOfOrigin, fee);
                        container.fee = container.getFee(container);
                        Containers.Add(container);
                        serialNumber++;
                        break;
                    }
                case Type.Quarter:
                    {
                        string disciption = " A Quarter sized container ";
                        string countryOfOrigin = " Netherlands ";
                        Container container = new QuarterContainer(serialNumber, disciption, countryOfOrigin, fee);
                        container.fee = container.getFee(container);
                        Containers.Add(container);
                        serialNumber++;
                        break;
                    }


            }
            serialNumber++;
        }
        public List<Container> getListOfContainers()
        {
            return Containers;
        }
        public string getResponse()
        {
            return response;
        }
        public State GetState()
        {
            return MachineState;
        }
        public void ResetState()
        {
            MachineState = State.WELCOME;
        }
    }
}
