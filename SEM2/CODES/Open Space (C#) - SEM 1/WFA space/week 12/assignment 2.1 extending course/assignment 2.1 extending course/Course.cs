using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Object_practice
{
    public class Course
    {
        //instance variables
        private string name;
        private int ec;
        //methods
        public Course(string name, int ec)
        {
            this.name = name;
            this.ec = ec;
        }
        public string Name { get { return name; } }
        public int Ec { get { return ec; } }   
        public void SetName(string name)
        { this.name = name; }

        public string GetName()
        { return this.name; }

        public void SetEc(int ec)
        { this.ec = ec; }

        public int GetEc()
        { return this.ec; }

        public string GetInfo()
        { return this.name + " has a total of: " + this.ec.ToString() + "ECs"; }
    }
}
