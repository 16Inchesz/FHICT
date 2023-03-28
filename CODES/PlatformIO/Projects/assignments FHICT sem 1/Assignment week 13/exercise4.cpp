//ICT & Technology, exercise 4, Johnson Domacasse, 29-11-2022
#include <Arduino.h>
#include <OpenRichShield.h>

#define LDRPIN A2

const int LDRSIZE = 15;
const int interval = 500;
unsigned long current_time;
unsigned long old_time;
int measurements[LDRSIZE] = {0};

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
    Serial.print("the average is:");
    Serial.println(avg);
    sum = 0;
    old_time = current_time;
  }
} 
