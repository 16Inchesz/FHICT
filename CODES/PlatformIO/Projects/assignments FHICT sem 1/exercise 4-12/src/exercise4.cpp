// Information & Technology, exercise 4, Johnson Domacasse, 15-11-2022
#include <Arduino.h>

//perimeter of circle is the following formula: C = 2 * π * r.
//Area of circle is the followng formula: A = π * r.

float radius;
float perimeter;
float area;

void setup() {
  //radius was not given so I chose a value.

  radius = 3.00;

  perimeter = 2.00 * PI * radius;
  
  area = PI * (radius * radius);


  //Print results
  Serial.begin(9600); 
  Serial.print("radius = ");
  Serial.print(radius);
  Serial.print(", perimeter = ");
  Serial.print(perimeter);
  Serial.print(", area = ");
  Serial.print(area);
}

void loop() {}