using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Serial_exercise_2___3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort1.Open();
        }
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            serialPort1.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if( serialPort1.BytesToRead > 0)
            {
                string line = serialPort1.ReadLine();
                lbxOutput.Items.Add(line);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (serialPort1.BytesToRead > 0)
            {
                string line = serialPort1.ReadLine();
                lbxOutput.Items.Add(line);
            }
        }
    }
}
