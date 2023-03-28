// ICT & Techonology, Johnson Domacasse, exercise 1, 13-12-2022

#include <Arduino.h>
#include <OpenRichShield.h>

#define BUTTON 9

struct BlinkingLED
{
  unsigned long previousTime;
  int ledState;
  unsigned int interval;
  int pin;
  bool on;
};

struct LED
{
  int pin;
  bool on;
};

struct LED yellowled;
struct BlinkingLED redled;
struct BlinkingLED greenled;
struct BlinkingLED blueled;


struct BlinkingLED CreateLed(int pin, int frequency)
{
  struct BlinkingLED led;
  led.pin = pin;
  led.interval = frequency;
  led.previousTime = 0;
  led.ledState = true;
  return led;
}

struct LED CreateLed(int pin)
{
  struct LED led;
  led.pin = pin;
  return led;
}

bool lastOn = false;
struct BlinkingLED OutputLED(struct BlinkingLED led)
{
  if (millis() - led.previousTime > led.interval)
  {
    led.ledState = !led.ledState;
    digitalWrite(led.pin, led.ledState);
    led.previousTime = millis();
  }
  return led;
}

struct LED OutputLED(struct LED led)
{
  digitalWrite(led.pin, led.on);
  return led;
}

int lastButtonState;
unsigned long buttonDebounceTime = 0;
struct LED ButtonLED(struct LED led)
{
  int buttonState;
  if (millis() - buttonDebounceTime > 40)
  {
    buttonState = digitalRead(BUTTON);
    if (buttonState != lastButtonState)
    {
      buttonDebounceTime = millis();
      if (buttonState == LOW)
      {
        Serial.println("here"); // debugging
        led.on = !led.on;
        OutputLED(led);
      }
      lastButtonState = buttonState;
    }
  }
  return led;
}

void PinModeIO()
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(greenled.pin, OUTPUT);
  pinMode(yellowled.pin, OUTPUT);
  pinMode(blueled.pin, OUTPUT);
  pinMode(redled.pin, OUTPUT);
}

void setup()
{
  Serial.begin(9600);
  yellowled = CreateLed(7);
  blueled = CreateLed(6, 500);  // blueled
  greenled = CreateLed(5, 250); // greenled
  redled = CreateLed(4, 125);   // redled
  PinModeIO();
}

void loop()
{
  redled = OutputLED(redled);
  greenled = OutputLED(greenled);
  blueled = OutputLED(blueled);
  yellowled = ButtonLED(yellowled);
}