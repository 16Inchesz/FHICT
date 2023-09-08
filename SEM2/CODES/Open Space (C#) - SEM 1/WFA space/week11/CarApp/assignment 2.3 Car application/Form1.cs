using System.Reflection.Metadata.Ecma335;

namespace assignment_2._3_Car_application
{
    public partial class Form1 : Form
    {
        public Car car1;
        public Form1()
        {
            InitializeComponent();
            car1 = new Car();
            car1.SetBrand("Toyota");
            car1.SetMaxSpeed(100);
            information.Text = car1.GetInfo();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnAccelerate_Click(object sender, EventArgs e)
        {
            car1.SpeedUp();
            information.Text = car1.GetInfo();
        }

        private void btnBreaks_Click(object sender, EventArgs e)
        {
            car1.SlowDown();
            information.Text = car1.GetInfo();
        }
    }
}