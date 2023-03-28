using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StreamingMusicApp
{
    public partial class Form1 : Form
    {
        List<User> users = new List<User>();
        int idnumber = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void lbUsers_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (tbAddress.Text == null || tbEmail.Text == null || tbUsername.Text == null)
            {
                return;
            }
            idnumber++;
            User userA = new User(idnumber, tbUsername.Text, tbEmail.Text, tbAddress.Text);
            users.Add(userA);
            lbAllUsers.Items.Add(userA.GetUserName());
        }
    }
}
