using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PoloClubApp
{
    internal class Device
    {
        //instance variables for each device.
        public int Id { get; set; }
        public string Name { get; set; }
        public string PlayerName { get; set; }
        //constructor.
        public Device(int id, string name, string playerName)
        {
            this.Id = id;
            this.Name = name;
            this.PlayerName = playerName;
        }

        /// <summary>
        /// this function checks if the device is assigned or not.
        /// </summary>
        /// <returns>false, if deivce is unassigned and true, if device is assigned.</returns>
        public virtual bool IsAssigned()
        {
            if (this.PlayerName == "")
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        /// <summary>
        /// This function assigns a device to a player based on the player's name.
        /// </summary>
        /// <param name="playername"></param>
        public virtual void AssignDevice(string playername)
        {
            this.PlayerName = playername;
        }

        /// <summary>
        /// this function returns a device that has been assigned to a player.
        /// </summary>
        /// <param name="device"></param>
        public virtual void ReturnDevice(Device device)
        {
            device.PlayerName = string.Empty;   //same as ""
        }

        /// <summary>
        /// this function gives the details of a device.
        /// </summary>
        /// <returns></returns>
        public virtual string GetDetails()
        {
            return this.Id + " " + this.Name + " " + this.PlayerName;
        }
    }
}
