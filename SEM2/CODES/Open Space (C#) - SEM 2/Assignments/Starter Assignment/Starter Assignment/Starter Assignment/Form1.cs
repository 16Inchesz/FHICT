using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Starter_Assignment
{
    public partial class Form1 : Form
    {
        Course courseName = new Course("ICT");
        
        int studentCounter = 0;
        int groupCounter = 1;

        public Form1()
        {
            InitializeComponent();
            lblStudentTotal.Text = Convert.ToString(studentCounter);
            lblGroupTotal.Text = Convert.ToString(groupCounter);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void btnAddStudent_Click(object sender, EventArgs e)
        {
            if (tbStudentName.Text != null )
            {
                //creating student
                courseName.AddStudent(tbStudentName.Text, Convert.ToInt32(tbStudentNumber.Text));

                //showing total students
                studentCounter++;
                lblStudentTotal.Text = Convert.ToString(studentCounter);

                //showing total groups
                if (studentCounter % 3 == 0)
                {
                    groupCounter++;
                    lblGroupTotal.Text = Convert.ToString(groupCounter); // can be outside of scope
                }
            }  
            //displaying all students and groups
            foreach (Student students in courseName.ShowStudent())
            {
                lbStudents.Items.Add(students.GetStudentName());
            }
            foreach(Group groups in courseName.ShowGroups())
            {
                lbGroups.Items.Add(groups.GetGroupName());
            }
        }
        //search for student button.
        private void btnSearchStudent_Click(object sender, EventArgs e)
        {
            if(tbSearchedStudent != null)
            {
                foreach(Student students in courseName.ShowStudent())
                {
                    int searchedStudentNum = Convert.ToInt32(tbStudentNumber.Text);
                    if (searchedStudentNum == students.GetStudentNumber())
                    {
                        lblSearchedStudent.Text = students.GetStudentName();    
                    }
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }
    }
}
