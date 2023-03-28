using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Starter_Assignment
{
    public class Group
    {
        public string groupName { get; set; }
        public List<Student> Students { get; set; }
        public Group(string name)
        {
            this.groupName = name;
            this.Students = new List<Student>();
        }

        public string GetGroupName()
        {
            return this.groupName;
        }

    }

}
