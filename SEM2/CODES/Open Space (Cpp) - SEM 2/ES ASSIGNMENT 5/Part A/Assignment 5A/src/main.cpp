#include <Arduino.h>
#include <avr/io.h>

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

// Debouncing variables
const int long DEBOUNCE_DELAY = 40;
unsigned long debounceTimeButton1 = 0;
unsigned long debounceTimeButton2 = 0;
int button1State = HIGH;
int lastButton1State = HIGH;
int button2State = HIGH;
int lastButton2State = HIGH;

// Variables for non-blocking delay
unsigned long previousMillis = 0;
const long interval = 500;

// Enum for button states
enum ButtonState {
  NO_BUTTON_PRESSED,
  BUTTON_1_PRESSED,
  BUTTON_2_PRESSED,
  BOTH_BUTTONS_PRESSED
};

/// @brief Debounce function for buttons.
/// @param buttonNumber 
/// @param debounceTime 
/// @param LastButtonState 
/// @param buttonMask 
/// @return ButtonState.
int DebounceButton(int buttonNumber, unsigned long& debounceTime, int& lastButtonState, int buttonMask) {
  int buttonState = HIGH;
  if (millis() - debounceTime > DEBOUNCE_DELAY) {
    buttonState = !(PINB & buttonMask);
    if (buttonState != lastButtonState) {
      debounceTime = millis();
      lastButtonState = buttonState;
    }
  }
  return buttonState;
}

/// @brief This functions handles the the button press, by toggling the bit in the PORD register that corresponds to ledPin.
/// @param ledPin 
void handleButtonPress(int ledPin) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    PORTD |= _BV(ledPin);
    previousMillis = currentMillis;
  }
}

void setup() {
  Serial.begin(9600);
  // Set input (buttons) and output (LEDs) pins.
  DDRD |= B01100000;
  DDRB &= ~BUTTON_1_MASK;
  DDRB &= ~BUTTON_2_MASK;
}

void loop() {
  unsigned long currentMillis = millis(); // Declare currentMillis at the start of the loop

  button1State = DebounceButton(1, debounceTimeButton1, lastButton1State, BUTTON_1_MASK);
  button2State = DebounceButton(2, debounceTimeButton2, lastButton2State, BUTTON_2_MASK);
  
  // Combine the button states into a single byte
  ButtonState combinedButtonPressState = static_cast<ButtonState>((button2State << 1) | button1State);
  
  // Use of a switch-case statement to handle different cases
  switch (combinedButtonPressState) {
    // Only button 1 is pressed
    case BUTTON_1_PRESSED: 
      handleButtonPress(LED_1_PIN);
      break;
    // Only button 2 is pressed
    case BUTTON_2_PRESSED: 
      handleButtonPress(LED_2_PIN);
      Serial.println("Hello World!");
      break;
    // Both buttons are pressed
    case BOTH_BUTTONS_PRESSED: 
      // Blink LEDs with alternating pattern.
      if (currentMillis - previousMillis >= interval) {
      // Toggle the bits in the PORTD register that correspond to LED_1_MASK and LED_2_MASK.
        PORTD ^= (LED_1_MASK | LED_2_MASK);
        previousMillis = currentMillis;
      }
      break;
    // No button is pressed
    default: 
      // Turn all LEDs off.
      PORTD &= ~_BV(LED_1_PIN);
      PORTD &= ~_BV(LED_2_PIN);
      break;
  }
}