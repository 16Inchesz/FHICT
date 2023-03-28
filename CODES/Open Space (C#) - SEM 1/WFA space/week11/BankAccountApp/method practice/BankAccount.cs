using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace method_practice
{

    public class BankAccount
    {
        private string client;
        private int accountNo;
        private double balance;

        public void initializeBankAccount(string newClient, int newAccountNo)
        {
            client = newClient;
            accountNo = newAccountNo;
            balance = 0;
        }
        public void DepositMoney(double amount)
        {
            balance += amount;
        }
        public bool WithdrawMoney(double amount)
        {
            if (amount <= balance)
            {
                balance -= amount;
                return true;
            }
            else
            {
                return false;
            }
        }
        public string GetInfo()
        {
            string info = balance.ToString();
            return info;
        }

        public override string ToString()
        {
            return "Client " + client + " (" + client + "):" + balance + " euro(s)";
        }
    }
}
