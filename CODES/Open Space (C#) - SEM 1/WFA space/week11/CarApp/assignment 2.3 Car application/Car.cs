using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace assignment_2._3_Car_application
{
    public class Car
    {
        private string brand;
        private int current_speed;
        private int max_speed;

        public void SetBrand(string brand)
        {
            this.brand = brand;
        }
        public void SetMaxSpeed(int max_speed)
        {
            this.max_speed = max_speed;
        }
        public string GetInfo()
        {
            return this.brand + " has a current speed of " + this.current_speed + " and a max speed of " + this.max_speed;
        }
        public void SpeedUp()
        {
            current_speed += 7;
            if (current_speed > max_speed)
            {
                current_speed = max_speed;
            }
        }
        public void SlowDown()
        {
            current_speed -= 10;
            if (current_speed < 0)
            {
                current_speed = 0;
            }
        }  
    }
}
