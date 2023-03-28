#include <Arduino.h>

#define FANPIN 3

void setup() {
  pinMode(FANPIN, OUTPUT);
}

byte fanduty = 0;
void setFanSpeed(byte speed) {
  // Determine the fan duty value.
  fanduty = map(speed, 0, 100, 0, 255);
  // Continues speed.
  analogWrite(FANPIN, fanduty);
}
void swingFan() {
  // Swing the fan.  
  analogWrite(FANPIN, 255);
  delay(45);
  // Continues speed.
  analogWrite(FANPIN, fanduty);
}

void loop() {
  setFanSpeed(50);
  swingFan();
}

