using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exercise_3
{
    public class Teacher : Person
    {
        //variables and enums
        private enum Position
        {
            juniorTeacher,
            teacher1,
            teacher2,
            teacher3,
            coordinator,
            director
        };
        private double salary;
        //constructor
        public Teacher(int age, string name, int pcn, int yearsAtSchool, double salary)
            :base(age, name, pcn, yearsAtSchool)
        {
            this.salary = salary;
        }
        //return methods
        public double GetSalary()
        {
            if (GetYearsAtSchool() % 3 == 0)
            {
                salary *= 1.05;
            }
            return salary;
        }
        
        //practical methods
        public void MakePromotion()
        {

        }

        //show info method
        public override string AsAString()
        {
            return base.AsAString() + " ;salary: " + GetSalary() + " ;position: " + Position.teacher3; //not finished product
        }
    }
}
