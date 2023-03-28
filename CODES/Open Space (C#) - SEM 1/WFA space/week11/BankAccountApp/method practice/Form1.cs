using System.Reflection.Metadata.Ecma335;

namespace method_practice
{
    public partial class Form1 : Form
    {
        BankAccount checkingAccount;
        BankAccount savingsAccount;
        public Form1()
        {
            InitializeComponent();
            checkingAccount = new BankAccount();
            savingsAccount = new BankAccount();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnDeposit_Click(object sender, EventArgs e)
        {
            if (rbChecking.Checked)
            {
                checkingAccount.DepositMoney(Convert.ToDouble(tbAmount.Text));
                lblCheckingBalance.Text = checkingAccount.GetInfo();
            }
            if (rbSavings.Checked)
            {
                savingsAccount.DepositMoney(Convert.ToDouble(tbAmount.Text));
                lblSavingsBalance.Text = savingsAccount.GetInfo();
            }
        }

        private void btnWithdraw_Click(object sender, EventArgs e)
        {
            if (rbChecking.Checked)
            {
                checkingAccount.WithdrawMoney(Convert.ToDouble(tbAmount.Text));
                lblCheckingBalance .Text = checkingAccount.GetInfo();
            }
            if (rbSavings.Checked)
            {
                savingsAccount.WithdrawMoney(Convert.ToDouble(tbAmount.Text));
                lblSavingsBalance.Text = savingsAccount.GetInfo();
            }
        }

        private void lblInfo_Click(object sender, EventArgs e)
        {

        }
    }
}