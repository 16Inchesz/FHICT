using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace exercise_3
{
    public class Student : Person
    {
        //variables
        private string country;
        private int nrOfECs;

        //constructor
        public Student(int age, string name, int pcn, int yearsAtSchool, string country, int nrOfECs)
            :base(age, name, pcn, yearsAtSchool)
        {
            this.country = country;
            this.nrOfECs = nrOfECs;
        }

        //return methods
        public string GetCountry(){ return country;  }
        public int GetNrOfECs(){ return nrOfECs; }
        
        //practical methods
        public void AddECs()
        {

        }

        //show info method
        public override string AsAString()
        {
            return base.AsAString() + " ;country: " + country + " ;nrOfECs: " + nrOfECs;
        }
    }
}
