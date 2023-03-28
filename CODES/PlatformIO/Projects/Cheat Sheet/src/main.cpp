#include <Arduino.h>

//I am keeping all the code in functions for the sake that it doesn't look like a bunch of errors when we open it.

//---------------------------------------------------------------------------------------------------------------------------------------

//standard pause in program using millis.
unsigned long last_time = 0;
const int INTERVAL = 500; //can be whatever you need.
void millis_delay(){
  if (millis() - last_time > INTERVAL){
    // do something.
    last_time = millis();
  }
}
//---------------------------------------------------------------------------------------------------------------------------------------

//button debouncing for more readble button.
#define BUTTON 6
unsigned long debounce_time = 0;
void button_debounce(){
  int buttonState;
  int lastButtonState;
  if (millis() - debounce_time > 40){   //ideal delay for debounce is around  40ms.
    buttonState = digitalRead(BUTTON);
    if (buttonState != lastButtonState){
      debounce_time = millis();
      if(buttonState == LOW){
        //do something.
      }
      lastButtonState = buttonState;
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------------------------

//standard blinking led program.
#define LED 5
bool led_state = LOW;
void blinking_led(){
  if (millis() - last_time > INTERVAL){
    led_state = !led_state;
    digitalWrite(LED, led_state);
    last_time = millis();
  }
}
//---------------------------------------------------------------------------------------------------------------------------------------

//sequence state pattern. could also be switch case.
int state = -1; //global state
void sequence_state(){
  state++; //increment state
  if (state > 2){
    state = 0; //begin state
  }

  if (state == 0){
    //do something fisrt.
  } else if (state == 1){
    //do something second
  } else if (state == 2){
    //do something third
  }
}
//---------------------------------------------------------------------------------------------------------------------------------------

void setup() {
}

void loop() {
}