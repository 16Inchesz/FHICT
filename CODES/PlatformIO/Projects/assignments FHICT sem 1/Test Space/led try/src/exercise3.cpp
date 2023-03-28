#include <Arduino.h>

#define LED 5

enum state {
  LEDON, LEDOFF, ONWAIT, OFFWAIT
};
enum state blinkMode = LEDON;

#define INTERVAL1 10

//at an interval of 0.01 seconds, you can barely see the led blink. so a 1000hz.
unsigned long Ledtime;
int led_state = LOW;
unsigned long current_time = millis();
int blinkMode;


void BlinkLED() {
  switch(blinkMode) {
    case LEDON:
       digitalWrite(LED, HIGH);
       blinkMode = ONWAIT;
       Ledtime = current_time;
    break;
    case ONWAIT:
      if ((current_time - Ledtime) > INTERVAL1) {
        blinkMode = LEDOFF;
      }
    break;
    case LEDOFF:
       digitalWrite(LED, LOW);
       blinkMode = OFFWAIT;
       Ledtime = current_time;
    break;
    case OFFWAIT:
      if ((current_time - Ledtime) > INTERVAL1) {
        blinkMode = LEDON;
      }
    break;
  }
}

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  current_time = millis();
  BlinkLED();
}