#include <Arduino.h>

int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, centimeters;
unsigned long previous_time = 0;
const int INTERVAL = 100;

//for a clean HIGH pulse
void ShortPulse(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}

long CalculateDistance(long duration){
  if (millis() - previous_time > INTERVAL){
    // Convert the time into a distance
    centimeters = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343 (this of sound);
  }
  previous_time = millis();
  return centimeters;
}
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long centimeters = CalculateDistance(duration);
  ShortPulse();
  duration = pulseIn(echoPin, HIGH);
  Serial.print(centimeters);
  Serial.print("cm");
  Serial.println();
}