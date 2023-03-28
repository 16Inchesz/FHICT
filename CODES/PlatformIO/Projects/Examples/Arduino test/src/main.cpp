#include <Arduino.h>

const int BUTTON = 8;
const int LED_GREEN = 5;
int lastButtonState = HIGH;
int state = 0;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_GREEN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON);
  if (buttonState != lastButtonState){
    if (buttonState == LOW){
      if (state == 0){
        digitalWrite(LED_GREEN, HIGH);
        Serial.println("on");
        state = 1;
      } else {
        digitalWrite(LED_GREEN, LOW);
         Serial.println("off");
         state = 0;
      }
    }
  }
  lastButtonState = buttonState;
}