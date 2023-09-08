using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Starter_Assignment
{

    public class Student
    {
        private string name;
        private int studentNumber;
        private string groupName;
        public Student(string name, int studentNumber, string groupName)
        {
            this.name = name;
            this.studentNumber = studentNumber;
            this.groupName = groupName;
        }

        public void SetStudentName(string name)
        {
            this.name = name;
        }
        public string GetStudentName()
        {
            return this.name;
        }
        public void SetStudentNumber(int studentNumber)
        {
            this.studentNumber = studentNumber;
        }
        public int GetStudentNumber()
        {
            return this.studentNumber;
        }
        public void GetInfo()
        {
            string information = name + "(" + studentNumber + ") - " + groupName;    
        }
    }
}
