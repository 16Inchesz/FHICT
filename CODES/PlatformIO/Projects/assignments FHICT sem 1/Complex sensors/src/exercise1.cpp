//ICT & Technology, exercise 1, Johnson Domacasse, 24-11-2022
#include <Arduino.h>
#include <OpenRichShield.h>

//constants
#define YELLOWLED 7
#define BLUELED 6
#define GREENLED 5
#define POTPIN A0

void initialize()
{
    pinMode(POTPIN, INPUT);
    pinMode(YELLOWLED, OUTPUT);
    pinMode(BLUELED, OUTPUT);
    pinMode(GREENLED, OUTPUT);
}
//setup
void setup() 
{
  Serial.begin(9600);
  initialize();
}

//Led controls
void yellow_on()
{
  digitalWrite(YELLOWLED, HIGH);
}
void blue_on()
{
  digitalWrite(BLUELED, HIGH);
}
void green_on()
{
  digitalWrite(GREENLED, HIGH);
}
void leds_off()
{
  digitalWrite(YELLOWLED, LOW);
  digitalWrite(BLUELED, LOW);
  digitalWrite(GREENLED, LOW);
}

void loop() {
  int angle = analogRead(POTPIN);
  int value = map(angle,0,1023,0,100);

  if (value == 0)
  {
    leds_off();
    yellow_on();
  } else if (value == 50)
  {
    leds_off();
    blue_on();
  } else if (value == 100)
  {
    leds_off();
    green_on();
  } else {
    leds_off();
  }
}
// add hysteris.