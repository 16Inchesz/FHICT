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
        private const int MaxPossibleWeight = 20000;
        private const int MaxPossibleVolume = 40;

        private string? response;
        private List<Container> Containers = new List<Container>();

        public bool isRefrigerated;
        public int serialNumber = 1;
        public int weight = 0;
        public int volume = 0;
        public decimal price = 0;
        
        Commands currentState = Commands.WELCOME;
        ContainerType containerType;

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

        public enum ContainerType
        {
            FULL,
            HALF,
            QUARTER
        }

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
            serialNumber++;
        }
        public List<Container> GetListOfContainers()
        {
            return Containers;
        }
        public string GetResponse()
        {
            return response;
        }
        public Commands GetCommand()
        {
            return currentState;
        }

        public void ResetState()
        {
            currentState = Commands.WELCOME;
        }

    }
}
