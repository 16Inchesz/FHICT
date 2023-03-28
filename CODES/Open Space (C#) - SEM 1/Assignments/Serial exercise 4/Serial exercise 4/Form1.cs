using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Serial_exercise_4
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
        private void LedOn_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("LedOn");
            if (serialPort1.BytesToRead > 0)
            {
                string LedOn = serialPort1.ReadLine();
                LedMode.Items.Add(LedOn);
            }
        }
        private void LedOff_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("LedOff");
            if (serialPort1.BytesToRead > 0)
            {
                string LedOff = serialPort1.ReadLine();
                LedMode.Items.Add(LedOff);
            }
        }

        private void LedBlinkOn_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("LedBlinkOn");
            if (serialPort1.BytesToRead > 0)
            {
                string LedBlinkOn = serialPort1.ReadLine();
                LedMode.Items.Add(LedBlinkOn);
            }
        }

        private void LedBlinkOff_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("LedBlinkOff");
            if (serialPort1.BytesToRead > 0)
            {
                string LedBlinkOff = serialPort1.ReadLine();
                LedMode.Items.Add(LedBlinkOff);
            }
        }
    }
}
