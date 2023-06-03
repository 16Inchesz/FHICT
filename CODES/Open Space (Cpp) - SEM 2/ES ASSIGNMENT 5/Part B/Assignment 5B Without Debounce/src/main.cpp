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

// Variables for non-blocking delay
volatile unsigned long previousMillis1 = 0;
volatile unsigned long previousMillis2 = 0;
volatile unsigned long previousBothButtonsMillis = 0;
const long interval = 500;

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

/// @brief Function to handle the different button inputs and LED outputs.
/// @param ledPin 
/// @param previousMillis 
/// @param prevButtonState 
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

/// @brief Function that checks if both buttons are pressed or not.
void checkBothButtonsPressed()
{
  if (!(PINB & BUTTON_1_MASK) && !(PINB & BUTTON_2_MASK))
  {
    bothButtonsPressed = HIGH;
  }
  else
  {
    bothButtonsPressed = LOW;
  }
}

/// @brief Function that turns off all LEDs.
void handleNoButtonsPressed()
{
  // We use the bitwise AND operator (&) to clear the bit in the PORTD register
  PORTD &= ~_BV(LED_1_PIN);
  PORTD &= ~_BV(LED_2_PIN);
  prevButton1State = HIGH;
  prevButton2State = HIGH;
}

/// @brief Function that blinks the LEDs based on the interval.
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

/// @brief Interrupt service routines for the buttons
/// @param  PCINT0_vect
ISR(PCINT0_vect)
{
  // Debug output
  // Serial.print("PINB state: ");
  // Serial.println(PINB, BIN);

  // Button 1 is pressed
  if (!(PINB & BUTTON_1_MASK) && prevButton1State)
  {
    handleButtonPress(LED_1_PIN, previousMillis1, prevButton1State);
  }

  // Button 2 is pressed
  if (!(PINB & BUTTON_2_MASK) && prevButton2State)
  {
    handleButtonPress(LED_2_PIN, previousMillis2, prevButton2State);
  }

  // Both buttons are pressed
  checkBothButtonsPressed();

  // Both buttons are not pressed
  handleNoButtonsPressed();
}

void loop()
{
  // If both buttons are pressed, blink the LEDs
  if (bothButtonsPressed)
  {
    blinkLEDs();
  }
}