using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exercise_3
{
    public class Person
    {
        //variables
        private int age;
        public string name;
        public int PCN;
        private int yearsAtSchool;

        //constructor
        public Person(int age, string name, int pcn, int yearsAtSchool)
        {
            this.age = age;
            this.name = name;
            this.PCN = pcn;
            this.yearsAtSchool = yearsAtSchool;
        }

        //return methods
        public int GetAge() { return age; }
        public string GetName() { return name; }
        public int GetPCN() { return PCN; }
        public int GetYearsAtSchool() { return yearsAtSchool; }

        //practical methods
        public void CelebrateBrithday()
        {
            age++;
        }
        public void StartAnotherYear()
        {
            yearsAtSchool++;
        }

        //show info method
        public virtual string AsAString()
        {
            return "Name: " + name + " ;age: " + age + " ;PCN: " + PCN + " ;YearsAtSchool: " + yearsAtSchool;
        }
    }
}
