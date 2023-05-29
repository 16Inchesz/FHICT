#include <Arduino.h>
#include <avr/io.h>

//digital pins for buttons and led
#define BUTTON_1_MASK (1 << PB2) 
#define BUTTON_2_MASK (1 << PB3)
#define LED_1_MASK (1 << PD5)
#define LED_2_MASK (1 << PD6)

//debouncing variabels
const int long debounceDelay = 40;
unsigned long debounceTime1 = 0;
unsigned long debounceTime2 = 0;
int button1State = HIGH;
int lastButton1State = HIGH;
int button2State = HIGH;
int lastButton2State = HIGH;

/// @brief Debounce function for button 1.
void DebounceButton1() {  
  if (millis() - debounceTime1 > debounceDelay) {
    //read button input
    button1State = !(PINB & BUTTON_1_MASK);
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
    button2State = !(PINB & BUTTON_2_MASK);
    if (button2State != lastButton2State) {
      debounceTime2 = millis();
      if (button2State == LOW) {
        // Button D11 is pressed, do something
      }
      lastButton2State = button2State;
    }
  }
}

void setup() {
  Serial.begin(9600);
  //set input(buttons) and output(LEDs) pins.
  DDRD = DDRD | B01100000;
  DDRB = DDRB &= ~BUTTON_1_MASK;
  DDRB = DDRB &= ~BUTTON_2_MASK;
}

void loop() {
  DebounceButton1();
  DebounceButton2();
  
  if (button1State == LOW && button2State == HIGH) {
    //turn on LED 1
    PORTD = (PORTD | LED_1_MASK) & 0x7F;
  } else if (button1State == HIGH && button2State == LOW) {
    //turn on LED 2
    PORTD = (PORTD | LED_2_MASK) & 0x7F;
    Serial.println("Hello World!");
    //delay for printing messages.
    delay(500);
  } else if (button1State == LOW && button2State == LOW) {
    //blink LEDs with alternating pattern.
    PORTD ^= ((LED_1_MASK) | _BV(LED_2_MASK));
    //delay for blinking.
    delay(500);
  } else if(button1State == HIGH && button2State == HIGH){
    //default case: turn all LEDs off.
    PORTD &= ~LED_1_MASK; 
    PORTD &= ~LED_2_MASK;
  }
}

