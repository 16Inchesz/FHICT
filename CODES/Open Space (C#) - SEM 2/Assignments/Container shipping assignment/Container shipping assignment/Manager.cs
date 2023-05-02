using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class Manager
    {
        //instance variables
        private const int MaxPossibleWeight = 20000;
        private const int MaxPossibleVolume = 40;

        private string? response;   //removal of '?' results in NULL warnings
        private List<Container> Containers = new List<Container>(); //list of containers

        public bool isRefrigerated;
        public int serialNumber = 1;
        public int weight = 0;
        public int volume = 0;
        public decimal price = 0;

        //states
        public enum Commands
        {
            WELCOME,
            TYPE,
            FRIDGE,
            WEIGHT,
            VOLUME,
            ACK,
            ERR
        }

        //container types
        public enum ContainerType
        {
            FULL,
            HALF,
            QUARTER
        }
        
        //init enum and state
        Commands currentState = Commands.WELCOME;
        ContainerType containerType;
        
        /// <summary>
        /// this method functions like sequence state pattern
        /// </summary>
        /// <param name="input"></param>
        /// <param name="commands"></param>
        public void StateChange(string input, Commands commands)
        {
            if (commands != Commands.ERR)
            {
                if (commands == Commands.WELCOME)
                {
                    if (input == null || input != "START")
                    {
                        currentState = Commands.ERR;
                    }
                    response = "TYPE";
                    currentState = Commands.TYPE;
                }

                if (commands == Commands.TYPE)
                {
                    if (input == null)
                    {
                        currentState = Commands.ERR;
                    }
                    else if (input == "FULL")
                    {
                        response = "FRIDGE";
                        containerType = ContainerType.FULL;
                        currentState = Commands.FRIDGE;
                    }
                    else if (input == "HALF")
                    {
                        response = "VOLUME";
                        containerType = ContainerType.HALF;
                        currentState = Commands.VOLUME;
                    }
                    else if (input == "QUARTER")
                    {
                        response = "ACK";
                        containerType = ContainerType.QUARTER;
                        currentState = Commands.ACK;
                    } else
                    {
                        currentState = Commands.ERR;
                    }
                }
                if (commands == Commands.FRIDGE)
                {
                    if (input == "YES")
                    {
                        isRefrigerated = true;
                        currentState = Commands.WEIGHT;
                        response = "WEIGHT";
                    } else if (input == "NO")
                    {
                        isRefrigerated = false;
                        currentState = Commands.WEIGHT;
                        response = "WEIGHT";
                    }
                    else
                    {
                        response = "ERR";
                        currentState = Commands.ERR;
                    }
                }
                if (commands == Commands.WEIGHT)
                {
                    if (Convert.ToInt32(input) >= MaxPossibleWeight || input == null || Convert.ToInt32(input) < 0)
                    {
                        currentState = Commands.ERR;
                        response = "ERR";
                    } else
                    {
                        weight = Convert.ToInt32(input);
                        currentState = Commands.ACK;
                        response = "ACK";
                    }
                }
                if (commands == Commands.VOLUME)
                {
                    if (Convert.ToInt32(input) >= MaxPossibleVolume || input == null || Convert.ToInt32(input) < 0)
                    {
                        currentState = Commands.ERR;
                        response = "ERR";
                    } else
                    {
                        volume = Convert.ToInt32(input);
                        currentState = Commands.ACK;
                        response = "ACK";
                    }
                }
                if (commands == Commands.ACK)
                {
                    ResetState();
                    AddContainer(containerType);
                }
            }
        }
        /// <summary>
        /// this method adds a container depending on which type.
        /// </summary>
        /// <param name="containerType"></param>
        public void AddContainer(ContainerType containerType)
        {
            switch (containerType)
            {
                case ContainerType.FULL:
                    {
                        string description = " Full Size Container ";
                        string originCountry = " Netherlands ";
                        Container container = new FullSizeContainer(serialNumber, originCountry, description, price, weight, isRefrigerated);
                        container.price = container.GetTotalFee(container);
                        Containers.Add(container);
                        serialNumber++;
                        break;
                    }
                case ContainerType.HALF:
                    {
                        string description = " Half Size Container ";
                        string originCountry = " Netherlands ";
                        Container container = new HalfSizeContainer(serialNumber, originCountry, description, price, volume);
                        container.price = container.GetTotalFee(container);
                        Containers.Add(container);
                        serialNumber++;
                        break;
                    }
                case ContainerType.QUARTER:
                    {
                        string description = " Quarter Size container ";
                        string originCountry = " Netherlands ";
                        Container container = new QuarterSizeContainer(serialNumber, originCountry, price, description);
                        container.price = container.GetTotalFee(container);
                        Containers.Add(container);
                        serialNumber++;
                        break;
                    }
            }
        }

        /// <summary>
        /// methos that returns the list of containers.
        /// </summary>
        /// <returns></returns>
        public List<Container> GetListOfContainers()
        {
            return Containers;
        }

        /// <summary>
        /// method that returns the response if it isnt null. (gives warning if removed)
        /// </summary>
        /// <returns></returns>
        public string GetResponse()
        {
            if (response != null)
            {
                return response;
            }
            return "";
        }

        /// <summary>
        /// this method returns the current state
        /// </summary>
        /// <returns></returns>
        public Commands GetCommand()
        {
            return currentState;
        }

        /// <summary>
        /// this methods puts the current state back in the initial state.
        /// </summary>
        public void ResetState()
        {
            currentState = Commands.WELCOME;
        }
    }
}
