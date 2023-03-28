#include <Arduino.h>
#include <OpenRichShield.h>

#define TEMPPIN A1
const int TEMP_COUNT = 14;
int temp[TEMP_COUNT] = { 0 };

void setup() {
  // put your setup code here, to run once:
}
int i;
float avg;
void loop() {
  for ( i = 0; i < TEMP_COUNT; i++) {
    temp[i] = analogRead(TEMPPIN);
    delay(2000);
  int sum = 0;
  for (i = 0; i < TEMP_COUNT; i++) {
    sum += temp[i]; // Add indexed element.
  } 
  avg /= TEMP_COUNT;
  }
  Serial.print(temp[i]);
  Serial.println(avg);
}



