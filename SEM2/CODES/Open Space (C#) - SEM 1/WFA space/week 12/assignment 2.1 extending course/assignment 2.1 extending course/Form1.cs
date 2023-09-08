using Object_practice;

namespace assignment_2._1_extending_course
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

        private void btnCreate_Click(object sender, EventArgs e)
        {
            courseA = new Course(txtbName.Text, Convert.ToInt32(txtbCredits.Text));
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