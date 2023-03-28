
#include <Arduino.h>

#define POTPIN A0

int value;
int quarter;

void setup() {
  pinMode(POTPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(POTPIN);
  quarter = map(value, 0, 1023, 0, 100);
  Serial.print(quarter);
  //to avoid issue with having 2 Q's print at the same time (issues), these if-statements were used.
  //The variable Quarter is printed to prove this.

  if (quarter >= 0 && quarter <25){
    Serial.println(": This is Q1");
  } else if (quarter >= 25 && quarter < 50){
    Serial.println(": This is Q2");
  } else if (quarter >= 50 && quarter < 75){
    Serial.println(": This is Q3");
  } else {
    Serial.println(": This is Q4");
  }
  delay(100); 
}