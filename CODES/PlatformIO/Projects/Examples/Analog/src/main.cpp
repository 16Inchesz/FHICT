#include <Arduino.h>

#define POTPIN A0
#define LEDPIN 6 
int value;

void setup() {
  pinMode(POTPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(POTPIN);
  analogWrite(LEDPIN, value);
  int percentage = map(value, 0, 1023, 0, 100);
  Serial.println(percentage );
}