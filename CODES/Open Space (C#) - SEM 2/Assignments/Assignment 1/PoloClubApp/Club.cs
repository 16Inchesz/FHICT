using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;
using System.Runtime.Remoting.Messaging;

namespace PoloClubApp
{
    class Club
    {
        //instance variables
        private string name;            // the name of the club
        private List<Device> devices;   // a list of devices

        //constructor
        public Club(string name)
        {
            this.name = name;
            this.devices = new List<Device>();
        }

        public string Name {get { return this.name; } } // read only property for Name


        //-----Provide your answers here-----

        /// <summary>
        /// function that gives you a list of all devices that are wearables using Iwearable interface.
        /// </summary>
        /// <returns>List of wearables.</returns>
        public List<Device> GetAllWearables()
        {
            List<Device> wearables = new List<Device>();
            foreach (Device dev in devices)
            {
                if (dev is IWearable)
                {
                    wearables.Add(dev);
                }
            }
            return wearables;
        }

        /// <summary>
        /// this function assigns a device(id) to a player (playerName). 
        /// </summary>
        /// <param name="id"></param>
        /// <param name="playerName"></param>
        public void AssignDevice(int id, string playerName)
        {
            Device device = GetDeviceById(id);
            if (device.IsAssigned() == true)    //check is the device has already been assigned.
            {
                MessageBox.Show("This device has already been assigned to a player");
            }
            else
            {
                device.AssignDevice(playerName);
            }
        }

        /// <summary>
        /// this function returns a device(id) from the player.
        /// </summary>
        /// <param name="id"></param>
        public void ReturnDevice(int id)
        {
            Device device = GetDeviceById(id);
            device.ReturnDevice(device);
        }

        /// <summary>
        /// this function makes a list and stores every device the player has been assigned in this list.
        /// </summary>
        /// <param name="playerName"></param>
        /// <returns>List Devices</returns>
        public List<Device> GetAllAssignedDevicesByPlayer(string playerName)
        {
            List<Device> devices = new List<Device>();
            foreach (Device dev in this.devices)
            {
                if (dev.PlayerName == playerName)
                {
                    devices.Add(dev);
                }
            }
            return devices;
        }

        /// <summary>
        /// this function generates a report by printing all of the phones and wearables assigned to this player in the form of a list string.
        /// </summary>
        /// <param name="playerName"></param>
        /// <returns>:List report</returns>
        public List<string> GenerateReportPerPlayer(string playerName)
        {
            List<string> report = new List<string>();   //list to return information
            List<Device> devices = new List<Device>();  //list to stores all devices
            int totalPhonesAssigned = 0;
            int totalWearablesAssigned = 0;
            devices = GetAllAssignedDevicesByPlayer(playerName);    //get all devices assigned to this player (playerName).
            report.Add("list of devices assigned to: " + playerName);
            report.Add("================================================");
            report.Add("Phones");
            report.Add("------------------------------------------------");
            foreach (Device dev in devices) //
            {
                if (dev is SmartPhone)  //checks if the device in the device list is a smartphone.
                {
                    report.Add("    " + dev.GetDetails());
                    totalPhonesAssigned++;
                }
            }
            report.Add("Wearables");
            report.Add("--------------------------------------------");
            foreach (Device dev in devices)
            {
                if (dev is IWearable)   //check if the device in the device list is a wearable (with interace) 
                {
                    report.Add("    " + dev.GetDetails());
                    totalWearablesAssigned++;
                }
            }
            report.Add("===========================================");
            report.Add("Number of phones " + totalPhonesAssigned + " Number of wearables " + totalWearablesAssigned);
            return report;
        }

        // -----The provided code below will not be graded, therefore should not be changed-----

        /// <summary>
        /// Provides all devices to the caller.
        /// </summary>
        /// <returns>List of devices</returns>
        public List<Device> GetAllDevices()
        {
            return this.devices;
        }

        /// <summary>
        /// Adds a device to the list of devices if unique id is provided.
        /// </summary>
        /// <param name="device">device to be added</param>
        public void AddDevice(Device device)
        {
            foreach (Device dev in this.devices)
            {
                if (dev.Id == device.Id)
                {
                    return;
                }
            }
            devices.Add(device);
        }

        /// <summary>
        /// Provides a device by a given id.
        /// </summary>
        /// <param name="id">the unique identity number of the requested device.</param>
        /// <returns>A device when found, otherwise null</returns>
        public Device GetDeviceById(int id)
        {
            foreach (Device dev in this.devices)
            {
                if (dev.Id == id)
                {
                    return dev;
                }
            }
            return null;
        }

    }
}
