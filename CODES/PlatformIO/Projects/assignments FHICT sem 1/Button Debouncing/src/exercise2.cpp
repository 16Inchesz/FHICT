//ICT & Technology, exercise 2, Johnson Domacasse, 08/12/2022
#include <Arduino.h>

#define BUTTON 2

bool toggle;
int lastButtonState = HIGH;
unsigned long DebounceTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP); // changed to input_pullup because of internal resistor
}
/*
  This is how I woud like to use my delay for programs (millis() function.)
  Instead of connecting the +5V to the button, you connect the ground to the button and then the other end of button to the dataPin.
  The internal resistor is automatically connected to the +5V so it only works when connected to ground.
*/
void loop() {
  int buttonState;
  if (millis() - DebounceTime > 40){
    buttonState = digitalRead(BUTTON);
    if (buttonState != lastButtonState){
      if (buttonState == LOW){
        Serial.println(toggle);
        toggle = !toggle;
      }
      lastButtonState = buttonState;
    }
    DebounceTime = millis();
  }
} 