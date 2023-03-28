using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace PoloClubApp
{
    internal class EmotionTracker : Device, IWearable
    {
        private int heartBeat = 0;
        private int conductance = 0;
        private int waterResistanceMeters = 0;

        public EmotionTracker(int id, string name, string playerName, int heartBeat, int conductance)
            :base(id, name, playerName)
        {
            this.heartBeat = heartBeat;
            this.conductance = conductance;
        }
        public int GetWaterResistanceMeters()
        {
            return waterResistanceMeters;
        }
    }
}v
