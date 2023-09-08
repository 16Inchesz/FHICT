using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance_Test
{
    public class Circle : Shape
    {
        private float radius;
        public Circle(float area, Color color, int lenght, int width, float radius) : base(area, color, lenght, width)
        {
            this.radius = radius;
        }
        public float Radius()
        {
            return this.radius;
        }

        public override string ToString()
        {
            return base.ToString();
        }
    }
}
