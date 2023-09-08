namespace assignment_3._1_advanced_controls
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (cmbColor.Text != null)
            {
                if (!cbUppercase.Checked)
                {
                    lbItems.Items.Add(cmbColor.SelectedItem);
                }
                else
                {
                    lbItems.Items.Add(cmbColor.SelectedItem.ToString().ToUpper());
                }
            }

            if (rbApples.Checked)
            {
                lbItems.Items.Add(rbApples.Text);   
            }
            if (rbBananas.Checked)
            {
                lbItems.Items.Add(rbBananas.Text);
            }
            if (rbOranges.Checked)
            {
                lbItems.Items.Add(rbOranges.Text);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            lbItems.Items.Clear();
        }

        private void cmbColor_SelectedIndexChanged(object sender, EventArgs e)
        {
            
            
        }

        private void lbItems_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}