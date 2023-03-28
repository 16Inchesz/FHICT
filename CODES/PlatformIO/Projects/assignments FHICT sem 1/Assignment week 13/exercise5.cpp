//ICT & Technology, exercise 4, Johnson Domacasse, 29-11-2022
#include <Arduino.h>
#include <OpenRichShield.h>

#define LDRPIN A2

const int LDRSIZE = 15;
const int AVGSIZE = 10;
const int interval = 1000;
unsigned long current_time;
unsigned long old_time;
int measurements[LDRSIZE] = {0};
float averages[AVGSIZE] = {0};
float max;
float min = 1023;


void setup() {
  Serial.begin(9600);
  pinMode(LDRPIN, INPUT);
}

int i;
int sum = 0;
void loop() {
  current_time = millis();
  if (current_time - old_time > interval){
    for (int i = 0; i < LDRSIZE; i++){
      measurements[i] = analogRead(LDRPIN);
      Serial.print(measurements[i]);
      Serial.print(" ");
    }
    for (int i = 0; i < LDRSIZE; i++){
      sum += measurements[i];
    }
    float avg = sum;
    avg /= LDRSIZE;
    for (int i = 0; i < AVGSIZE; i++){
      averages[i] = avg;
      if (averages[i] < min){
        min = averages[i];
      }
      if (averages[i] > max){
        max = averages[i];
      }
    }
    Serial.print("\nthe average is:");
    Serial.print(avg);
    Serial.print("\nthe minimum brightness is: ");
    Serial.print(min);
    Serial.print("\nthe maximum brightness is: ");
    Serial.print(max);
    Serial.println("\n");
    sum = 0;
    old_time = current_time;
  }
} 
