using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PoloClubApp
{
    internal class FitTracker : Device, IWearable   //apply interface because a FitTracker is a wearable.
    {
        //instance variables.
        private int waterResistanceMeters;
        private string color;

        //constructor with device base.
        public FitTracker(int id, string name, string playerName, int waterResistanceMeters, string color)
            :base(id, name, playerName)
        {
            this.waterResistanceMeters = waterResistanceMeters;
            this.color = color;
        }

        /// <summary>
        /// this function checks if the FitTracker is assigned or not.
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
        /// This function assigns a FitTracker to a player based on the player's name.
        /// </summary>
        /// <param name="playername"></param>
        public override void AssignDevice(string playername)
        {
            this.PlayerName = playername;
        }

        /// <summary>
        /// this function returns a FitTracker that has been assigned to a player.
        /// </summary>
        /// <param name="device"></param>
        public override void ReturnDevice(Device device)
        {
            device.PlayerName = string.Empty;   //same as ""

        }
        /// <summary>
        /// this function returns the water resistance of the FitTracker in meters.
        /// </summary>
        /// <returns></returns>
        public int GetWaterResistanceMeters()
        {
            return waterResistanceMeters;
        }

        /// <summary>
        /// this function gives the details of a FitTracker.
        /// </summary>
        /// <returns></returns>
        public override string GetDetails()
        {
            return this.Id + " " + this.Name + " " + this.PlayerName + " Water resistance: " + this.waterResistanceMeters + "Meters Color: " + this.color;
        }
    }
}
