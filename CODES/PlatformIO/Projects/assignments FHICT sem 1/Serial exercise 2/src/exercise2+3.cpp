#include <Arduino.h>

void setup() {
  Serial.begin(9600); // Baud rate
}
void loop() {
  Serial.println("Johnny five is alive!");
  delay(1000); 
}