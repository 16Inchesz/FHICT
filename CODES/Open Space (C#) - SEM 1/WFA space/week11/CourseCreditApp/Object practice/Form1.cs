namespace Object_practice
{
    public partial class Form1 : Form
    {
        public Course courseA;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            courseA = new Course();
            courseA.SetName(txtbName.Text);
            courseA.GetName();
            courseA.SetEc(Convert.ToInt32(txtbCredits.Text));
            courseA.GetEc();    
        }

        private void btnShow_Click(object sender, EventArgs e)
        {
            lblInformation.Text = courseA.GetInfo();
        }
    }
}