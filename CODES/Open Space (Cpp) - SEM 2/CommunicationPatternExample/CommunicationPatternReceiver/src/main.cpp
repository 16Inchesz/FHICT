#include <Arduino.h>

#include "ExampleReceiver.h"

void setup() {
  Serial.begin(9600);
  SetupLeds();
}

void loop() { fsm(); }