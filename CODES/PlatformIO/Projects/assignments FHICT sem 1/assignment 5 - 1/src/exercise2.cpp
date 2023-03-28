// ICT & Techonology, Johnson Domacasse, exercise 1, 13-12-2022

#include <Arduino.h>
#include <OpenRichShield.h>

const int INTERVAL = 500;

struct LED {
  int pin;
  bool on;
};

struct LED led;
unsigned long Ledtime = 0;

struct LED CreateLED(const int ledPin, bool ledOn){
  led.pin = ledPin;
  led.on = ledOn;
  return led;
}

// it needs a return type since the function type isn't "void".
bool lastOn;
void OutputLED(struct LED led){
  if(lastOn != led.on){
    if (led.on == true){
      digitalWrite(led.pin, HIGH);
    }
    else{
      digitalWrite(led.pin, LOW);
    }
    Serial.println(led.on);
  }
  lastOn = led.on;
}

void setup() {
  Serial.begin(9600);
  led = CreateLED(6, false);
}

void loop() {
  OutputLED(led);

  if (millis() - Ledtime > INTERVAL){
    led.on = !led.on;
    Ledtime = millis();
  }
}