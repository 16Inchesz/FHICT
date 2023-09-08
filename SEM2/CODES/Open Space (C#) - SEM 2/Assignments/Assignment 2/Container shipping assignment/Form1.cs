using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Container_shipping_assignment
{
    public partial class Form1 : Form
    {
        Server server = new Server();

        public Form1()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnStartConnection_Click(object sender, EventArgs e)
        {
            btnStartConnection.Enabled = false;
            server.Start_server();
        }

        private void btnGetReport_Click(object sender, EventArgs e)
        {
            lbContainers.Items.Clear();
            foreach (Container container in server.GetListOfContainers())
            {
                string info = container.GetInfo(container);
                lbContainers.Items.Add(info);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
        }
    }
}