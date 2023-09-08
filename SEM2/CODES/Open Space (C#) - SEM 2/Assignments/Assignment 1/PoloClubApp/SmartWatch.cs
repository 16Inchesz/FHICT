using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PoloClubApp
{
    internal class SmartWatch : Device, IWearable   //apply interface because a SmartWatch is a wearable.
    {

        public int waterResistanceMeters;
        public int screenSize;

        //constructor with device base
        public SmartWatch(int id, string name, string playerName, int wateResistanceMeters, int screenSize)
            :base(id, name, playerName)
        {
            this.waterResistanceMeters = wateResistanceMeters;
            this.screenSize = screenSize;  
        }

        /// <summary>
        /// this function checks if the SmartWatch is assigned or not.
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
        /// This function assigns a SmartWatch to a player based on the player's name.
        /// </summary>
        /// <param name="playername"></param>
        public override void AssignDevice(string playername)
        {
            this.PlayerName = playername;
        }

        /// <summary>
        /// this function returns a SmartWatch that has been assigned to a player.
        /// </summary>
        /// <param name="device"></param>
        public override void ReturnDevice(Device device)
        {
            device.PlayerName = string.Empty;   //same as ""
        }

        /// <summary>
        /// this function returns the water resistance of the SmartWatch in meters.
        /// </summary>
        /// <returns></returns>
        public int GetWaterResistanceMeters()
        {
            return waterResistanceMeters;
        }

        /// <summary>
        /// this function gives the details of a SmartWatch.
        /// </summary>
        /// <returns></returns>
        public override string GetDetails()
        {
            return this.Id + " " + this.Name + " " + this.PlayerName + " Water resistance: " + this.waterResistanceMeters + "Meters Screensize: " + this.screenSize;
        }
    }
}
