#include <Arduino.h>

#define ANALOG0PIN A0

const int TIMEINTERVAL = 1000;  //1 second time interval.
unsigned long previousTime = 0;

//map function that returns floats instead of longs.
float MapAnalogValuesToVoltage(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);
  pinMode(ANALOG0PIN, INPUT);
}  

void loop() {
  if (millis() - previousTime > TIMEINTERVAL){
    float value = analogRead(ANALOG0PIN);
    // analog to voltage converter. (analog value, analog min, analog max, voltage min, voltage max)
    float voltage = MapAnalogValuesToVoltage(value, 0.0, 1023.0, 0.0, 5.0);
    Serial.println(voltage);
    previousTime = millis();
  }
}