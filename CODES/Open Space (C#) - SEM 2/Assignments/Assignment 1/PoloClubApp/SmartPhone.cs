using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;

namespace PoloClubApp
{
    internal class SmartPhone : Device 
    {
        //constructor with device base.  
        public SmartPhone(int id, string name, string playerName)
            :base(id, name, playerName)
        {   
        }

        /// <summary>
        /// this function checks if the SmartPhone is assigned or not.
        /// </summary>
        /// <returns>false, if deivce is unassigned and true, if device is assigned.</returns>
        public override bool IsAssigned()
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
        /// This function assigns a SmartPhone to a player based on the player's name.
        /// </summary>
        /// <param name="playername"></param>
        public override void AssignDevice(string playername)
        {
            this.PlayerName = playername;
        }

        /// <summary>
        /// this function returns a SmartPhone that has been assigned to a player.
        /// </summary>
        /// <param name="device"></param>
        public override void ReturnDevice(Device device)
        {
            device.PlayerName = string.Empty;   //same as ""

        }

        /// <summary>
        /// this function gives the details of a SmartPhone.
        /// </summary>
        /// <returns></returns>
        public override string GetDetails()
        {
            return this.Id + " " + this.Name + " " + this.PlayerName;
        }
    }
}
