using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Starter_Assignment
{
    public class Course
    {
        //variables and lists
        private string name;
        private List<Student> studentList;
        private List<Group> GroupList;
        private List<Student> studentView;
        private List<Group> groupView;

        private int groupCounter = 1;
        public Course(string name)
        {
            this.name = name;
            this.studentList = new List<Student>();
            this.GroupList = new List<Group>();
        }

        //main code
        public void AddStudent(string name, int studentNumber) 
        {
            //if there are no groups, make new group and add student (initialize)
            if (GroupList.Count == 0)
            {
                this.GroupList.Add(new Group("group " + groupCounter));  
                this.studentList.Add(new Student(name, studentNumber, GroupList[groupCounter - 1].groupName ));  
                GroupList[groupCounter - 1].Students.Add(new Student(name, studentNumber, GroupList[groupCounter - 1].groupName));  
            } 
            //if the group is already full (3 students), make new group then add student
            else if (GroupList.Count > 0){
                if (GroupList[groupCounter - 1].Students.Count > 2)
                {
                    groupCounter ++;
                    this.GroupList.Add(new Group("group " + groupCounter)); 
                    this.studentList.Add(new Student(name, studentNumber, GroupList[groupCounter - 1].groupName)); 
                    GroupList[groupCounter - 1].Students.Add(new Student(name, studentNumber, GroupList[groupCounter - 1].groupName));
                }
                //if group is not full (3 Students), add student to current group.
                else
                {
                    this.studentList.Add(new Student(name, studentNumber, GroupList[groupCounter - 1].groupName));
                    GroupList[groupCounter - 1].Students.Add(new Student(name, studentNumber, GroupList[groupCounter - 1].groupName));
                }
            }
        }
        //itirating through lists to display students and groups.
        public Array ShowStudent()
        {
            foreach (Student Students in studentList)
            {
                studentView = new List<Student>();
                studentView.Add(Students);
                studentView.ToArray();  //no need to convert
            }
            return studentView.ToArray();
        }
        public Array ShowGroups()
        { 
            foreach (Group groups in GroupList)
            {
                groupView = new List<Group>();
                groupView.Add(groups);
                groupView.ToArray();
            }
            return groupView.ToArray();
        }
        public void SearchByStudentNumber()
        {

        }
        public void SearchByGroup()
        {

        }
    }
}
