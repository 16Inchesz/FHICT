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

namespace Assignment_2A_SEM2
{
    public partial class Form1 : Form
    {
        string previous_output = "";
        Server server;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }
        private void BTN_Start_Click(object sender, EventArgs e)
        {
            BTN_Start.Enabled = false;
            server = new Server();
            server.Start_server();
        }
        private void BTN_show_containers_Click(object sender, EventArgs e)
        {
            ListBoxContainers.Items.Clear();
            foreach(Container container in server.getListOfContainers())
            {
                string info = container.getInfoContainer(container);
                ListBoxContainers.Items.Add(info);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string output = server.GetOutput();
            if (output != previous_output) 
            {
                ListBoxInput.Items.Add(output);
                previous_output = output;
            }
        }
    }
}
