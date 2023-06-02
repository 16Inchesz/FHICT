#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// Pin numbers
#define BUTTON_1_PIN PB2
#define BUTTON_2_PIN PB3
#define LED_1_PIN PD5
#define LED_2_PIN PD6

// Digital pin masks for buttons and LEDs
#define BUTTON_1_MASK _BV(BUTTON_1_PIN)
#define BUTTON_2_MASK _BV(BUTTON_2_PIN)
#define LED_1_MASK _BV(LED_1_PIN)
#define LED_2_MASK _BV(LED_2_PIN)

// Variables for button state
volatile bool prevButton1State = HIGH;
volatile bool prevButton2State = HIGH;
volatile bool bothButtonsPressed = LOW;
volatile int lastButton1State = HIGH;
volatile int lastButton2State = HIGH;
unsigned long debounceTimeButton1 = 0;

// Variables for non-blocking delay
volatile unsigned long previousMillis1 = 0;
volatile unsigned long previousMillis2 = 0;
volatile unsigned long previousBothButtonsMillis = 0;
const long interval = 500;
const long DEBOUNCE_DELAY = 40;

// Enum for button states
enum ButtonState
{
  NO_BUTTON_PRESSED,
  BUTTON_1_PRESSED,
  BUTTON_2_PRESSED,
  BOTH_BUTTONS_PRESSED
};

void setup()
{
  Serial.begin(9600);
  // Set input (buttons) and output (LEDs) pins.
  DDRD |= B01100000;
  DDRB &= ~BUTTON_1_MASK;
  DDRB &= ~BUTTON_2_MASK;

  // Enable pin change interrupt on button pins
  PCICR |= _BV(PCIE0);
  PCMSK0 |= _BV(PCINT2);
  PCMSK0 |= _BV(PCINT3);

  // Enable global interrupts
  sei();
}

void handleButtonPress(int ledPin, volatile unsigned long &previousMillis, volatile bool &prevButtonState)
{
  if (prevButtonState)
  {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
      PORTD ^= _BV(ledPin);
      previousMillis = currentMillis;
    }
    prevButtonState = LOW;
  }
  else
  {
    PORTD &= ~_BV(ledPin);
    prevButtonState = HIGH;
  }
}

void handleNoButtonsPressed() {
  PORTD &= ~_BV(LED_1_PIN);
  PORTD &= ~_BV(LED_2_PIN);
  prevButton1State = HIGH;
  prevButton2State = HIGH;
}

int DebounceButton(int buttonNumber, volatile unsigned long& debounceTime, int buttonMask) {
  int buttonState = LOW;
  if (millis() - debounceTime > DEBOUNCE_DELAY) {
    buttonState = (PINB & buttonMask) ? LOW : HIGH;
    debounceTime = millis();
  }
  return buttonState;
}

// Interrupt service routines for the buttons
ISR(PCINT0_vect) {
  // Button 1 is pressed
  int button1State = DebounceButton(1, debounceTimeButton1, BUTTON_1_MASK);
  if (button1State == HIGH && prevButton1State == LOW) {
    handleButtonPress(LED_1_PIN, previousMillis1, prevButton1State);
  }
  prevButton1State = button1State;

  // Button 2 is pressed
  int button2State = DebounceButton(2, debounceTimeButton1, BUTTON_2_MASK);
  if (button2State == HIGH && prevButton2State == LOW) {
    handleButtonPress(LED_2_PIN, previousMillis2, prevButton2State);
  }
  prevButton2State = button2State;

  // Both buttons are pressed
  if (button1State == HIGH && button2State == HIGH) {
    bothButtonsPressed = HIGH;
  } else {
    bothButtonsPressed = LOW;
  }

  // Both buttons are not pressed
  if (button1State == LOW && button2State == LOW) {
    handleNoButtonsPressed();
  }
}


void blinkLEDs()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousBothButtonsMillis >= interval)
  {
    // Toggle the bit in the PORTD register that corresponds to LED_1_PIN.
    if (PORTD & LED_1_MASK)
    {
      PORTD &= ~LED_1_MASK;
      PORTD |= LED_2_MASK;
    }
    else
    {
      PORTD &= ~LED_2_MASK;
      PORTD |= LED_1_MASK;
    }
    previousBothButtonsMillis = currentMillis;
  }
}

void loop() {
  // If both buttons are pressed, blink the LEDs
  if (bothButtonsPressed) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousBothButtonsMillis >= interval) {
      // Toggle the bits in the PORTD register that correspond to LED_1_MASK and LED_2_MASK.
      PORTD ^= (LED_1_MASK | LED_2_MASK);
      previousBothButtonsMillis = currentMillis;
    }
  }
}