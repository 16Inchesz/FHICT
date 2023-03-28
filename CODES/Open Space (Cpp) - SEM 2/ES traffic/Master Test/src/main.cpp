#include <Arduino.h>

const int INTERVAL = 3000;
unsigned long previous_time = 0;
int command = 0;
void setup() {  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if (millis() - previous_time > INTERVAL) {
    command = !command;
    if (command){
    Serial.write("A;");}
    else {
    Serial.write("B;");
    }
    previous_time = millis();
  }
}