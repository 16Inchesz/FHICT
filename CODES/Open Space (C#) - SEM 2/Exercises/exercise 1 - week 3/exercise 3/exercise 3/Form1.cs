using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace exercise_3
{
    public partial class Form1 : Form
    {
        Person person;
        Student student;
        Teacher teacher;
        public Form1()
        {
            InitializeComponent();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
        //methods
        private void ShowInfoPerson()
        {

        }
        private void ShowInfoStudent()
        {

        }
        private void ShowInfoTeacher()
        {

        }
        
        //buttons for creating person
        private void btnNewPerson_Click(object sender, EventArgs e)
        {
            person = new Person(Convert.ToInt16(tbPersonAge.Text), tbPersonName.Text, 
                Convert.ToInt16(tbPcn.Text), Convert.ToInt16(tbYearsAtSchool.Text));
        }

        private void btnNewStudent_Click(object sender, EventArgs e)
        {
            student = new Student(Convert.ToInt16(tbPersonAge.Text), tbPersonName.Text,
                Convert.ToInt16(tbPcn.Text), Convert.ToInt16(tbYearsAtSchool.Text),
                tbCountry.Text, Convert.ToInt16(tbECs.Text));
        }

        private void btnNewTeacher_Click(object sender, EventArgs e)
        {
            teacher = new Teacher(Convert.ToInt32(tbPersonAge.Text), tbPersonName.Text,
                Convert.ToInt16(tbPcn.Text), Convert.ToInt16(tbYearsAtSchool.Text),
                Convert.ToInt32(tbSalary.Text));
        }

        //buttons for show information.
        private void btnShowInfoPerson_Click(object sender, EventArgs e)
        {
            lbShowInformation.Items.Add(person.AsAString());
            tbShowPersonName.Text = person.GetName();
            tbShowPersonPcn.Text = Convert.ToString(person.GetPCN());
        }

        private void btnShowInfoStudent_Click(object sender, EventArgs e)
        {
            lbShowInformation.Items.Add(student.AsAString());
            tbShowPersonName.Text = student.GetName();
            tbShowPersonPcn.Text = Convert.ToString(student.GetPCN());
        }

        private void btnShowInfoTeacher_Click(object sender, EventArgs e)
        {
            lbShowInformation.Items.Add(teacher.AsAString());
            tbShowPersonName.Text = teacher.GetName();
            tbShowPersonPcn.Text = Convert.ToString(teacher.GetPCN());
        }

        private void btnCelebrateBirthday_Click(object sender, EventArgs e)
        {
            person.CelebrateBrithday();
        }

        private void btnStartAnotherSchoolyear_Click(object sender, EventArgs e)
        {
            person.StartAnotherYear();
        }

        private void btnAddECs_Click(object sender, EventArgs e)
        {
            student.AddECs();
        }
    }
}
