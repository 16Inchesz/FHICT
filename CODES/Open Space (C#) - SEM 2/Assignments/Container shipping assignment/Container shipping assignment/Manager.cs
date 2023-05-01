using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Security;
using System.Text;
using System.Threading.Tasks;

namespace Container_shipping_assignment
{
    public class Manager
    {
        private List<Container> containers;
        private Server server;

        public Manager(Server server)
        {
            this.server = server;
            this.containers = new List<Container>();
        }

        public void GenerateReport()
        {
            foreach (Container container in containers)
            {

            }
        }

        public void CreateContainer(string type, int serialNumber, string originCountry, string description, int weightOrVolume)
        {
            Container container;
            switch (type)
            {
                case "FULL":
                    container = new FullSizeContainer(serialNumber, originCountry, description, weightOrVolume);    //fix this
                    container.GetTotalFee();
                    break;
                case "HALF":
                    container = new HalfSizeContainer(serialNumber, originCountry, description, weightOrVolume);    //fix this
                    container.GetTotalFee();
                    break;
                case "QUARTER":
                    container = new QuarterSizeContainer(serialNumber, originCountry, description);
                    container.GetTotalFee();
                    break;
                default:
                    throw new ArgumentException("Invalid container type.");
            }
            containers.Add(container);
        }

    }
}
