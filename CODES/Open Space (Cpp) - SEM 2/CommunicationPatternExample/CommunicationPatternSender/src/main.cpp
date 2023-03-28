#include <Arduino.h>

#include "ExampleSender.h"

void setup() { Serial.begin(9600); }

void loop() { fsm(); }