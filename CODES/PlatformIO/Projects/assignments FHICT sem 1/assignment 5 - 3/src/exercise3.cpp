// ICT & Techonology, Johnson Domacasse, exercise 1, 13-12-2022

#include <Arduino.h>
#include <OpenRichShield.h>

struct BlinkingLED{
  unsigned long previousTime;
  int ledState;
  unsigned int interval;
  int pin;
  bool on;
};

struct BlinkingLED led;
struct BlinkingLED CreateLed(int pin, int frequency, bool ledOn, unsigned long previous_time, bool led_state){
  led.pin = pin;
  led.interval = frequency;
  led.on = ledOn; 
  led.previousTime = previous_time;
  led.ledState = led_state;
  return led;
}

bool lastOn = false;
struct BlinkingLED OutputLED(struct BlinkingLED led){
  if (millis() - led.previousTime > led.interval){    //What I noticed is if you don't make sure that interval in also an unsigned int/long it will give you a warning.
    led.ledState = !led.ledState;                     
    digitalWrite(led.pin, led.ledState);
    led.previousTime = millis();
  }
  return led;
}

void setup() {
  Serial.begin(9600);
  led = CreateLed(6, 500, false, 0, false); //blueled
}

void loop() {
  led = OutputLED(led);
}