//ICT & Technology, exercise 1, Johnson Domacasse, 29-11-2022
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

const int interval_2hz = 500; 
unsigned long RedLedTime;
int RedLedState = LOW;
void BlinkRedLed(){
  if (current_time - RedLedTime > interval_2hz/2){
    RedLedState = !RedLedState;
    digitalWrite(REDLED, RedLedState);
    RedLedTime = current_time;
  }
}

const int interval_5hz = 200;
unsigned long YellowLedTime;
int YellowLedState = LOW;
void BlinkYellowdLed(){
  if (current_time - YellowLedTime > interval_5hz/2){
    YellowLedState = !YellowLedState;
    digitalWrite(YELLOWLED, YellowLedState);
    YellowLedTime = current_time;
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

unsigned long GreenLedTime;
int GreenLedState = LOW;
const int interval_1hz = 1000;
void BlinkSlowGREENLED(){
  if (current_time - GreenLedTime > interval_1hz/2){
    GreenLedState = !GreenLedState;
    digitalWrite(GREENLED,GreenLedState);
    GreenLedTime = current_time;
  }
}

const int interval_10hz = 100;
void BlinkFastGREENLED(){
  if (current_time - GreenLedTime > interval_10hz/2){
    GreenLedState = !GreenLedState;
    digitalWrite(GREENLED,GreenLedState);
    GreenLedTime = current_time;
  }
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