using System.Security.Cryptography;

namespace bmi_calculator_WFA
{
    public partial class Form1 : Form
    {


        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void label1_Click(object sender, EventArgs e)
        {

        }
        private void Weight_TextChanged(object sender, EventArgs e)
        {


        }

        private void Height_TextChanged(object sender, EventArgs e)
        {

        }
        private void Calculate_BMI_Click(object sender, EventArgs e)
        {
            double weight = Convert.ToDouble(Weight.Text);
            double height = Convert.ToDouble(Height.Text);
            double meters = height / 100;
            double bmi = weight / (meters * meters);
            string underweight = "You are underweight.";
            string normalweight = "You are normal weight.";
            string overweight = "your are overweight";
            string obese = "you are obese";
            string Advice = "Please go see a doctor";

            this.label3.Text = bmi.ToString("0.00");

            if ((bmi >= 0) && (bmi < 18.5))
            {
                result.Text = underweight;
            } else if ((bmi >= 18.5) && (bmi < 25))
            {
                result.Text = normalweight;
            } else if ((bmi >= 25) && (bmi < 30))
            {
                result.Text = overweight;
            } else if (bmi >= 30)
            {
                result.Text = obese;  
                advice.Text = Advice;
            }
        }
    }
}