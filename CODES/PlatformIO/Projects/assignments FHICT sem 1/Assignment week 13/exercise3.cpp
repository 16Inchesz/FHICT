//ICT & Technology, exercise 3, Johnson Domacasse, 29-11-2022
#include <Arduino.h>
#include <OpenRichShield.h>

#define REDLED 4
#define YELLOWLED 7
#define GREENLED 5
#define BUTTON 9
#define POTPIN A0

const int PRESSED = LOW;
unsigned long current_time;

void setup() {
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(POTPIN, INPUT);
  display.on();
}

const int REDLEDON = 0;
const int REDONWAIT = 1;
const int REDLEDOFF = 2;
const int REDOFFWAIT = 3;
int RedBlinkMode = REDLEDON;
const int interval_2hz = 500; 
unsigned long RedLedTime;
void BlinkRedLed(){
  switch(RedBlinkMode){
  case REDLEDON:
    digitalWrite(REDLED, HIGH);
    RedBlinkMode = REDONWAIT;
    RedLedTime = current_time;
  break;
  case REDONWAIT:
    if (current_time - RedLedTime > interval_2hz){
      RedBlinkMode = REDLEDOFF;
    }
  break;
  case REDLEDOFF:
    digitalWrite(REDLED, LOW);
    RedBlinkMode = REDOFFWAIT;
    RedLedTime = current_time;
    break;
  case REDOFFWAIT:
    if (current_time - RedLedTime > interval_2hz){
      RedBlinkMode = REDLEDON;
    }
  }
}

const int YELLOWLEDON = 0;
const int YELLOWONWAIT = 1;
const int YELLOWLEDOFF = 2;
const int YELLOWOFFWAIT = 3;
int YELLOWBlinkMode = YELLOWLEDON;
const int interval_5hz = 200;
unsigned long YellowLedTime;
void BlinkYellowdLed(){
  switch(YELLOWBlinkMode){
  case YELLOWLEDON:
    digitalWrite(YELLOWLED, HIGH);
    YELLOWBlinkMode = YELLOWONWAIT;
    YellowLedTime = current_time;
  break;
  case YELLOWONWAIT:
    if (current_time - YellowLedTime > interval_5hz){
      YELLOWBlinkMode = YELLOWLEDOFF;
    }
  break;
  case YELLOWLEDOFF:
    digitalWrite(YELLOWLED, LOW);
    YELLOWBlinkMode = YELLOWOFFWAIT;
    YellowLedTime = current_time;
    break;
  case YELLOWOFFWAIT:
    if (current_time - YellowLedTime > interval_5hz){
      YELLOWBlinkMode = YELLOWLEDON;
    }
  }
}

const int GREENLEDON = 0;
const int GREENONWAIT = 1;
const int GREENLEDOFF = 2;
const int GREENOFFWAIT = 3;
int GREENBlinkMode = GREENLEDON;
unsigned long GreenLedTime;
const int interval_1hz = 1000;
void BlinkSlowGREENLED(){
  switch(GREENBlinkMode){
  case GREENLEDON:
    digitalWrite(GREENLED, HIGH);
    GREENBlinkMode = GREENONWAIT;
    GreenLedTime = current_time;
  break;
  case GREENONWAIT:
    if (current_time - GreenLedTime > interval_1hz){
      GREENBlinkMode = GREENLEDOFF;
    }
  break;
  case GREENLEDOFF:
    digitalWrite(GREENLED, LOW);
    GREENBlinkMode = GREENOFFWAIT;
    GreenLedTime = current_time;
    break;
  case GREENOFFWAIT:
    if (current_time - GreenLedTime > interval_1hz){
      GREENBlinkMode = GREENLEDON;
    }
  }
}

const int interval_10hz = 100;
void BlinkFastGREENLED(){
  switch(GREENBlinkMode){
  case GREENLEDON:
    digitalWrite(GREENLED, HIGH);
    GREENBlinkMode = GREENONWAIT;
    GreenLedTime = current_time;
  break;
  case GREENONWAIT:
    if (current_time - GreenLedTime > interval_10hz){
      GREENBlinkMode = GREENLEDOFF;
    }
  break;
  case GREENLEDOFF:
    digitalWrite(GREENLED, LOW);
    GREENBlinkMode = GREENOFFWAIT;
    GreenLedTime = current_time;
    break;
  case GREENOFFWAIT:
    if (current_time - GreenLedTime > interval_10hz){
      GREENBlinkMode = GREENLEDON;
    }
  }
}

int value;
int state = HIGH;
bool IsButtonPressed(){
  int buttonState = digitalRead(BUTTON);
  if (buttonState != state){
    state = buttonState;
    if (buttonState == LOW) {
      return true;
    }
  }
  return false;
}

int angle;
int percentage;
int old_percentage; 
void AngleToDisplay(){
  angle = analogRead(POTPIN);
  percentage = map(angle, 0, 1023, 0, 100);
  if (percentage != old_percentage){
    display.show(percentage);
  }
  old_percentage = percentage;
}

bool toggle = false;

void loop() {
  current_time = millis();
  BlinkRedLed();
  BlinkYellowdLed();
  if (IsButtonPressed())
  {
     toggle = !toggle;
  }
  if (toggle) {
    BlinkFastGREENLED();
  } else {
    BlinkSlowGREENLED();  
  }
  AngleToDisplay();
}