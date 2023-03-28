#include <Arduino.h>

#define REDLED 4
#define BUTTON1 8
#define BUTTON2 9

unsigned long current_time;
unsigned long previous_time = 0;
const int INTERVAL = 1000;

int button1State;
int button2State;
int currentButton2State;
int lastButton1State = HIGH;
int lastButton2State;

bool led_state = false;
String message;

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

void Button1Toggle(){
  button1State = digitalRead(BUTTON1);
  if (button1State != lastButton1State){
    lastButton1State = button1State;
    Serial.println("LedOn"); 
  }
}
                                      //  Neither serial.print nor assigning value to message works as the output. Why?
                                      //  Ask about the listbox as well.
void Button2Toggle(){
  button2State = digitalRead(BUTTON2);
  if (button2State != lastButton2State){
    lastButton2State = button2State;
    Serial.println("LedOff");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(REDLED, OUTPUT);
  pinMode(BUTTON1,INPUT_PULLUP);
  pinMode(BUTTON2,INPUT_PULLUP);
}

void loop() {
  Button1Toggle();
  Button2Toggle();
  ChangingStates();
  current_time = millis();
  if (Serial.available()) {
    message = Serial.readStringUntil('\n');
    message.trim(); // strip off '\r’.
  if (message == "LedOn") {
    LED_MODE = LedOn;
  } else if (message == "LedOff") {
      LED_MODE = LedOff;
    } else if (message == "LedBlinkOn"){
      LED_MODE = LedBlink;
    } else if (message == "LedBlinkOff"){
      LED_MODE = LedOff;
    }
  }
}