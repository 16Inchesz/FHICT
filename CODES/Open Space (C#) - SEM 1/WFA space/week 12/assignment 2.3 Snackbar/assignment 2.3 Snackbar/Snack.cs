using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace assignment_2._3_Snackbar
{
    public class Snack
    {
        private string name;
        private double price;
        private int amount;

        public Snack(string name, double price, int amount) 
        {
            this.name = name;
            this.price = price;
            this.amount = amount;
        }
        public bool DecreaseStock(int amount)
        {
            return true;
        }
        public string GetName()
        {
            return name;
        }
        public string GetPrice()
        {
            return Convert.ToString(price);
        }
        public string GetAmountInStock()
        {
            return Convert.ToString(amount);
        }
    }
}
