#include <avr/io.h>
#include <avr/interrupt.h>
#include <Arduino.h>

// Pin numbers
#define BUTTON_SLOW_PIN PB2
#define BUTTON_FAST_PIN PB3
#define LED_0_PIN PD5
#define LED_1_PIN PD6
#define LED_2_PIN PD8
#define LED_3_PIN PD9

// Digital pin masks for buttons and LEDs
#define BUTTON_SLOW_MASK _BV(BUTTON_SLOW_PIN)
#define BUTTON_FAST_MASK _BV(BUTTON_FAST_PIN)
#define LED_0_MASK _BV(LED_0_PIN)
#define LED_1_MASK _BV(LED_1_PIN)
#define LED_2_MASK _BV(LED_2_PIN)
#define LED_3_MASK _BV(LED_3_PIN)

// Counter variable
volatile uint8_t counter = 0;
volatile uint8_t compareValue = 6250;
volatile uint8_t maxCompareValue = 62500;

// millis counter interval
const long interval = 500;

// Variables for button states
volatile bool buttonSlowState = HIGH;
volatile bool buttonFastState = HIGH;

// Variables for timer speed adjustment
//Default compare value for 4 times per second
volatile uint16_t timerCompareValue = 62500; 

void setup()
{
  // Set input (buttons) and output (LEDs) pins
  DDRD |= B11100100;
  DDRB &= ~BUTTON_SLOW_MASK;
  DDRB &= ~BUTTON_FAST_MASK;

  // Enable pin change interrupt on button pins
  PCICR |= _BV(PCIE0);
  PCMSK0 |= _BV(PCINT2);
  PCMSK0 |= _BV(PCINT3);

  // Set Timer 1 in CTC mode with prescaler of 64
  // Clear TCCR1A register
  TCCR1A = 0; 
  // Set WGM12 for CTC mode, CS11 and CS10 for prescaler 64
  TCCR1B = _BV(WGM12) | _BV(CS11) | _BV(CS10); 

  // Set output compare match value for desired timer speed
  OCR1A = timerCompareValue;

  // Enable Timer 1 compare match interrupt (timer interrupt mask)
  TIMSK1 |= _BV(OCIE1A);

  // Enable global interrupts
  sei();
}

/// @brief Function that slows down the rate of which the counter is displayed on LEDs.
void handleButtonSlow()
{
  if (buttonSlowState)
  {
    if (timerCompareValue < maxCompareValue)
      timerCompareValue += compareValue; // Increase compare value for slower speed
  }
  buttonSlowState = LOW;
}

/// @brief Function that speeds up the rate of which the counter is displayed on LEDs.
void handleButtonFast()
{
  if (buttonFastState)
  {
    if (timerCompareValue > compareValue)
      timerCompareValue -= compareValue; // Decrease compare value for faster speed
  }
  buttonFastState = LOW;
}

/// @brief Function to display the counter on the LEDs.
void displayCounter()
{
  PORTD = (PORTD & B11100011) | (counter << 2); // Display counter on LED pins (PD5, PD6, PD8, PD9)
}

/// @brief This interrupt serivce acts as the button handler for this system.
/// @param  PCINT0_vect
ISR(PCINT0_vect)
{
  //read button 1.
  if (!(PINB & BUTTON_SLOW_MASK))
  {
    handleButtonSlow();
  }

  //read button 2.
  if (!(PINB & BUTTON_FAST_MASK))
  {
    handleButtonFast();
  }
}

/// @brief This interrupts service acts as timer we use in order to display the values on the LEDs and blinik the built in LED.
/// @param  TIMER1_COMPA_vect
ISR(TIMER1_COMPA_vect)
{
  // 4 bit vounter cant display more than the value 15 (1111).
  counter++;
  if (counter > 15){
    counter = 0;
  }

  //display counter on LEDs.
  displayCounter();

  //turn on built in LED.
  if (millis() % 1000 < interval){
    PORTD |= _BV(PD4);
  }
  else{
    PORTD &= ~_BV(PD4);
  }

  cli();  //Disable interrupts.
  OCR1A = timerCompareValue; // Update compare match value for timer speed adjustment
  sei();  //Enable interrupts.
}

void loop()
{
  // Empty loop
}