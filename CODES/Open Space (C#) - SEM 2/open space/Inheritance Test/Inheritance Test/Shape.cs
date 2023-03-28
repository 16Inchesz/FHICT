using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance_Test
{
    public class Shape
    {
        float area;
        Color color;
        int lenght, width;
        public Shape(float area, Color color, int lenght, int width)
        {
            this.area = area;
            this.color = color;
            this.lenght = lenght;
            this.width = width;
        }
        public float GetArea()
        {
            return area;
        }
        public Color GetColor()
        {
            return color;
        }
        public int GetLength()
        {
            return lenght;
        }
        public int Width()
        {
            return width;
        }

        public virtual string ToString()
        {
            return "area: " + area + " ;color: " + color + " ; length: " + lenght + " ;width: " + width + " ;radius: " + radius;
        }
    }
}
