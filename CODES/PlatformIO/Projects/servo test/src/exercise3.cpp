#include <Arduino.h>

#define TRIG_PIN 11
#define ECHO_PIN 12

long centimeters;
unsigned long previous_time = 0;
unsigned long previous_time_calculate = 0;
const int INTERVAL = 1000;

//short LOW pulse beforehand for a clean HIGH pulse
void ShortPulse(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
}

long CalculateDistance(long duration){
  if (millis() - previous_time_calculate > 250){
    centimeters = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343 (speed of sound calculation   
  }
  return centimeters;
}

void setup(){
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop(){
  if (millis() - previous_time > INTERVAL){
    ShortPulse();
    long duration = pulseIn(ECHO_PIN, HIGH);
    centimeters = CalculateDistance(duration);
    Serial.print(centimeters);
    Serial.print("cm");
    Serial.println();
  }
}