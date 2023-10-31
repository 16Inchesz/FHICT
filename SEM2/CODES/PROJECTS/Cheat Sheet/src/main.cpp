#include <Arduino.h>
#include <stdbool.h>
#include <stdio.h>

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
const int DEBOUNCETIME = 40;
void button_debounce(){
  int buttonState;
  int lastButtonState;
  if (millis() - debounce_time > DEBOUNCETIME){   //ideal delay for debounce is around  40ms.
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

//Swapping 2 values
void swap(int* x, int* y){
  int temp = *x;
  *x = *y;
  *y = temp;
}
//---------------------------------------------------------------------------------------------------------------------------------------

//bubble sort 
bool bubble_sort(int* a, int array_size){ //note sizeof array must always be divided by the first value to get actual size
  if(a == NULL){
    return false;
  }
  for (int i = 0; i < array_size - 1; i++){
    for (int j = 0; j < array_size - i - 1; j++){
      if (a[j] > a[j+1]){
        swap(&a[j], &a[j+1]);
      }
    }
  }
  return true;
}
//---------------------------------------------------------------------------------------------------------------------------------------

void setup() {
}

void loop() {
}