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

//YELLOWLED = 5HZ; 200ms
//GREENLED = 10HZ; 100ms (if button pressed, else 1000ms)


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
  if (current_time - RedLedTime > interval_2hz){
    RedLedState = !RedLedState;
    digitalWrite(REDLED, RedLedState);
    RedLedTime = current_time;
  }
}

const int interval_5hz = 200;
unsigned long YellowLedTime;
int YellowLedState = LOW;
void BlinkYellowdLed(){
  if (current_time - YellowLedTime > interval_5hz){
    YellowLedState = !YellowLedState;
    digitalWrite(YELLOWLED, YellowLedState);
    YellowLedTime = current_time;
  }
}

int value;
int state = LOW;
int lastState;
int GetButton(){
  value = digitalRead(BUTTON);
  return value;
}

unsigned long GreenLedTime;
int GreenLedState = LOW;
const int interval_1hz = 1000;
void BlinkSlowGREENLED(){
  if (current_time - GreenLedTime > interval_1hz){
    GreenLedState = !GreenLedState;
    digitalWrite(GREENLED,GreenLedState);
    GreenLedTime = current_time;
  }
}

const int interval_10hz = 100;
void BlinkFastGREENLED(){
  if (current_time - GreenLedTime > interval_10hz){
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

void loop() {
  current_time = millis();
  BlinkRedLed();
  BlinkYellowdLed();
  int buttonValue;
  buttonValue = GetButton();
  if (buttonValue == PRESSED)
  {
    BlinkFastGREENLED();
  } else {
    BlinkSlowGREENLED();  
  }
  AngleToDisplay();
}