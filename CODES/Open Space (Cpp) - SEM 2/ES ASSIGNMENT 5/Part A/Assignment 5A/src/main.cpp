#include <Arduino.h>
#include <avr/io.h>

//digital pins for buttons and led
#define BUTTON_1_PIN 10 
#define BUTTON_2_PIN 11 
#define LED_1_PIN 5      
#define LED_2_PIN 6  

//debouncing variabels
const int long debounceDelay = 40;
unsigned long debounceTime1 = 0;
unsigned long debounceTime2 = 0;
int button1State = HIGH;
int lastButton1State = HIGH;
int button2State = HIGH;
int lastButton2State = HIGH;

void setup() {
  Serial.begin(9600);
  //set input(buttons) and output(LEDs) pins.
  DDRB = DDRB & ~(_BV(BUTTON_1_PIN) | _BV(BUTTON_2_PIN));
  DDRD = DDRD | _BV(LED_1_PIN) | _BV(LED_2_PIN);
}

void loop() {
  DebounceButton1();
  DebounceButton2();
  
  if (button1State == LOW && button2State == HIGH) {
    //turn on LED 1
    PORTD |= _BV(LED_1_PIN);    
  } else if (button1State == HIGH && button2State == LOW) {
    //turn on LED 2
    PORTD |= _BV(LED_2_PIN);
    Serial.println("Hello World!");
    //delay for printing messages.
    delay(500);
  } else if (button1State == LOW && button2State == LOW) {
    //blink LEDs with alternating pattern.
    PORTD ^= _BV(LED_1_PIN) | _BV(LED_2_PIN);
    //delay for blinking.
    delay(500);
  } else {
    //default case: turn all LEDs off.
    PORTD &= ~(_BV(LED_1_PIN) | _BV(LED_2_PIN));  // Turn off LEDs D5 and D6
  }
}

/// @brief Debounce function for button 1.
void DebounceButton1() {
  if (millis() - debounceTime1 > debounceDelay) {
    //read the current button state and assign value using ternary operator "?".
    button1State = (PINB & _BV(BUTTON_1_PIN)) ? HIGH : LOW;

    if (button1State != lastButton1State) {
      debounceTime1 = millis();
      if (button1State == LOW) {
        // Button D10 is pressed, do something
      }
      lastButton1State = button1State;
    }
  }
}

/// @brief Debounce function for button 2.
void DebounceButton2(){
  if (millis() - debounceTime2 > debounceDelay) {
    //read the current button state and assign value using ternary operator "?".
    button2State = (PINB & _BV(BUTTON_2_PIN)) ? HIGH : LOW;

    if (button2State != lastButton2State) {
      debounceTime2 = millis();
      if (button2State == LOW) {
        // Button D11 is pressed, do something
      }
      lastButton2State = button2State;
    }
  }
}
