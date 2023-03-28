// Information & Technology, exercise 2, Johnson Domacasse, 17-11-2022
#include <Arduino.h> 

const int BUTTON = 8;
const int UNKNOWN = 0; // State: Not pressed, released or hold
const int PRESSED = 1; // State: Button pressed
const int RELEASED = 2; // State: Button released
const int PRESSED_HOLD = 3; // State: Button pressed and hold
int state = UNKNOWN;
int lastValue = HIGH;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
}

// the code "lastValue = value" can be written in different places and still produce the same results.
// I included these locations in the form of comments.

void loop()
{
  int value = digitalRead(BUTTON);
  if (value != lastValue){
    if (value == LOW){
      state = PRESSED;
    }
    else {
      state = RELEASED;
    }
    lastValue = value;
  }
  else {
    if (value == LOW){
      state = PRESSED_HOLD;
    }
    else{ 
      state = UNKNOWN;
    }
  }
  //lastValue = value;
  
  if (state == PRESSED){
    Serial.println("PRESSED");
  } else if (state == RELEASED) {
        Serial.println("RELEASED");
  } else if (state == PRESSED_HOLD) {
      Serial.println("PRESSED_HOLD");
  }
  state = UNKNOWN;
  //lastValue = value;
}