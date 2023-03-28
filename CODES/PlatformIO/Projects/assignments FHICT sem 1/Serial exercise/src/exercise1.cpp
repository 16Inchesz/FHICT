#include <Arduino.h>

#define REDLED 4


unsigned long current_time;
unsigned long previous_time = 0;
const int INTERVAL = 1000;
bool led_state = false;

enum state {
  LedOn, LedOff, LedBlink
};
enum state LED_MODE = LedOff;

void ChangingStates(){
  switch(LED_MODE)
  {
    case(LedOff):
      digitalWrite(REDLED, LOW);
      break;
    case(LedOn):
      digitalWrite(REDLED, HIGH);
      break;
    case(LedBlink):
      if ((current_time - previous_time) > INTERVAL){
        led_state = !led_state;
        digitalWrite(REDLED, led_state);
        previous_time = current_time;        
      break;
      }
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(REDLED, OUTPUT);
}

void loop() {
  ChangingStates();
  current_time = millis();
  String message;
  if (Serial.available()) {
  message = Serial.readStringUntil('\n');
  message.trim(); // strip off '\r’.
  if (message == "LedOn") {
    LED_MODE = LedOn;
  } else if (message == "LedOff") {
      LED_MODE = LedOff;
    } else if (message == "LedBlink"){
      LED_MODE = LedBlink;
    }
  }
}