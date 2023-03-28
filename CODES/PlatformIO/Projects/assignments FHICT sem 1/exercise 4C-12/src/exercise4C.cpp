//ICT & Technology, exercise 4, Johnson Domacasse, 17-11-2002
#include <Arduino.h>

#define LDRPIN A2
int brightness;
int daytime;
int max = 1023, min = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LDRPIN, INPUT);
}

void loop() {
  // using the code below, I determined what the treshholds for the diffeerent daytimes were using a flashlight (no actual time to use).
  // sunlight highest is 698, daylight highest is 410, evening highest is 210, night time is 145. 
  
  /*
  if (brightness > min){
    min = brightness;
  }
  if (brightness < max){
    max = brightness;
  }
  Serial.print("dark = ");
  Serial.println(max);
  Serial.print("highlight = ");
  Serial.println(min);
  delay(1000);
  */

  brightness = analogRead(LDRPIN);
  Serial.print(brightness);
  if (brightness >= 0 && brightness < 145){
    Serial.println(" it's nighttime");
  } else if (brightness >= 145 && brightness < 210){
    Serial.println(" it's evening");
  } else if (brightness >= 210 && brightness < 410){
    Serial.println(" it's daylight");
  } else {
    Serial.println(" It's sunny");
  }
}