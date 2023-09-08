using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PoloClubApp
{
    public partial class PoloClubAppForm : Form
    {

        // Provide your answers here

        /// <summary>
        /// this part makes a list of devices and assigned all wearables into that list. The list is then displayed.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnViewAllWearables_Click(object sender, EventArgs e)
        {
            lbOverview.Items.Clear();
            List<Device> devices = myClub.GetAllWearables();
            foreach (Device device in devices)
            {
                lbOverview.Items.Add(device.GetDetails());
            }
        }

        /// <summary>
        /// this part assigns a device (id) to the name(playerName) that is read.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnAssign_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(cbDevice.SelectedItem.ToString());
            string PlayerName = tbPlayerName.Text;
            if ("" == PlayerName)
            {
                MessageBox.Show("No name has been entered");
            }
            else 
            { 
                myClub.AssignDevice(id, PlayerName); 
            }
        }
        
        /// <summary>
        /// this part simply returns the device that has already been assigned. 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnReturn_Click(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(cbDevice.SelectedItem);
            myClub.ReturnDevice(id);
        }

        /// <summary>
        /// this part reads the playername. If the players exists, it will show all assigned devices to that player.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnShowAssignedDevices_Click(object sender, EventArgs e)
        {
            lbOverview.Items.Clear();
            List<Device> devices = myClub.GetAllAssignedDevicesByPlayer(tbPlayerName.Text);
            foreach (Device device in devices)
            {
                lbOverview.Items.Add(device.GetDetails());
            }
        }

        /// <summary>
        /// this part reads the playername. If the player exist, it will create a report of them.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnGeneratePlayerTextReport_Click(object sender, EventArgs e)
        {
            lbOverview.Items.Clear();
            List<string> report = myClub.GenerateReportPerPlayer(tbPlayerNameForFile.Text);
            foreach (string line in report)
            {
                lbOverview.Items.Add(line);
            }
        }

        // -----The provided code below will not be graded, therefore should not be changed-----

        private Club myClub;
        public PoloClubAppForm()
        {
            InitializeComponent();
            myClub = new Club("Polo Koningen - powered by <Johnson>");
            this.Text = myClub.Name;
            this.addSomeTestingStuff();
            this.fillComboBoxDevices();
        }

        private void addSomeTestingStuff()
        {
            myClub.AddDevice(new SmartPhone(101, "iPhone X", string.Empty));
            myClub.AddDevice(new SmartWatch(202, "Apple Watch Sport", string.Empty, 5, 38));
            myClub.AddDevice(new FitTracker(300, "Fitbit Ionic", string.Empty, 1, "pink"));
            myClub.AddDevice(new SmartWatch(203, "Motorola Moto 360", string.Empty, 9, 40));
            myClub.AddDevice(new SmartPhone(102, "iPhone 9", string.Empty));
            myClub.AddDevice(new SmartPhone(103, "Galaxy S9", string.Empty));
            myClub.AddDevice(new FitTracker(301, "Fitbit Alta HR", string.Empty, 8, "blue"));
            myClub.AddDevice(new SmartPhone(104, "Pixels 2", string.Empty));
            myClub.AddDevice(new SmartWatch(204, "Samsung Gear Sport", string.Empty, 2, 42));
            myClub.AddDevice(new FitTracker(302, "Fitbit Charge 2", string.Empty, 10, "black"));
            myClub.AddDevice(new FitTracker(303, "Misfit Ray", string.Empty, 0, "black"));

        }
        private void fillComboBoxDevices()
        {
            foreach (Device dev in myClub.GetAllDevices())
            {
                cbDevice.Items.Add(dev.Id);
            }
        }

        private void btnViewAllDevices_Click(object sender, EventArgs e)
        {
            this.lbOverview.Items.Clear();
            foreach (Device dev in myClub.GetAllDevices())
            {
                this.lbOverview.Items.Add(dev.GetDetails());    //list of all the devices.
            }

        }

        private void lbOverview_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
