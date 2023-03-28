#include <Arduino.h>

#define RED 11
#define GREEN 9
#define BLUE 10

/*  chartreuse (223, 255, 0)
    chocolate (63, 0, 15)
    magenta (255, 0 , 255)
    midnightblue (25, 25, 112)
    thistle (216, 191, 216)
*/
void setLedColor(int red, int green, int blue){
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}

enum state{
  color_chartruese, color_chocolate, color_magenta, color_midnightblue, color_thistle
};

enum state Led_color = color_chartruese;

void ChangeColor(){
  switch(Led_color)
  {
    case color_chartruese:
      setLedColor(223, 255, 0);
      Serial.println("chartruese");
      delay(3000);
      Led_color = color_chocolate;
      break;
    case color_chocolate:
      setLedColor(63, 0, 15);
      Serial.println("chocolate");
      delay(3000);
      Led_color = color_magenta;
      break;
    case color_magenta:
      setLedColor(255, 0, 255);
      Serial.println("magenta");
      delay(3000);
      Led_color = color_midnightblue;
      break;
    case color_midnightblue:
      setLedColor(25, 25, 112);
      Serial.println("midnightblue");
      delay(3000);
      Led_color = color_thistle;
      break;
    case color_thistle:
      setLedColor(216, 191, 216);
      Serial.println("thistle");
      delay(3000);
      Led_color = color_chartruese;
      break;
  }
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ChangeColor();
}