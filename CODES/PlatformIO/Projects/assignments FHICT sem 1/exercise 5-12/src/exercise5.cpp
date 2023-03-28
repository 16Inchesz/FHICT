// Information & Technology, exercise 5, Johnson Domacasse, 15-11-2022
#include <Arduino.h>

//perimeter of circle is the following formula: C = 2 * π * r.
//Area of circle is the followng formula: A = π * r.

float radius;
float perimeter;
float area;

int r;
int C;
int A;
void setup() {
  //radius was not given so I chose a value.
  // add 0.5 to it so if its still the same whole number nothing changes, but if it's a new whole number, it gives the illusion that it's rounded.
  radius = 5.0;
  r = (radius + 0.5);

  perimeter = 2.00 * PI * radius;
  C = (perimeter + 0.5);

  area = PI * (radius * radius);
  A = (area + 0.5);

  //Print results
  Serial.begin(9600); 
  Serial.print("radius = ");
  Serial.print(r);
  Serial.print(", perimeter = ");
  Serial.print(C);
  Serial.print(", area = ");
  Serial.print(A);
}

void loop() {}