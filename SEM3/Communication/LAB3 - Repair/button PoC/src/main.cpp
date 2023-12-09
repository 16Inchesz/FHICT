#include <Arduino.h>
const int button1Pin = 2;  
const int button2Pin = 3;
const int button3Pin = 4;
const int button4Pin = 5;

unsigned long debounceTime = 0;

const int DEBOUNCETIME = 40;

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonState4 = 0; 

// int buttonDebounce(){
//   int buttonState;
//   int lastButtonState;
//   if (millis() - debounceTime > DEBOUNCETIME){
//     buttonState = digitalRead(button1Pin);
//     if (buttonState != lastButtonState){
//       debounceTime = millis();
//       if(buttonState == LOW){
//         return 1;
//       }
//       lastButtonState = buttonState;
//     }
//   }
//   return 0;
// }

void setup() {
  Serial.begin(9600);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
}

void WriteState1(int state){
  if (state == HIGH) {
    // turn LED on:
    Serial.println("button 1: 1");
  } else {
    // turn LED off:
    Serial.println("button 1: 0");
  }
}

void WriteState2(int state){
  if (state == HIGH) {
    // turn LED on:
    Serial.println("button 2: 1");
  } else {
    // turn LED off:
    Serial.println("button 2: 0");
  }
}

void WriteState3(int state){
  if (state == HIGH) {
    // turn LED on:
    Serial.println("button 3: 1");
  } else {
    // turn LED off:
    Serial.println("button 3: 0");
  }
}

void WriteState4(int state){
  if (state == HIGH) {
    // turn LED on:
    Serial.println("button 4: 1");
  } else {
    // turn LED off:
    Serial.println("button 4: 0");
  }
}
void loop() {
  buttonState1 = digitalRead(button1Pin);
  buttonState2 = digitalRead(button2Pin);
  buttonState3 = digitalRead(button3Pin);
  buttonState4 = digitalRead(button4Pin);

  WriteState1(buttonState1);
  WriteState2(buttonState2);
  WriteState3(buttonState3);
  WriteState4(buttonState4);
  
  Serial.println();

  delay(500);
}
