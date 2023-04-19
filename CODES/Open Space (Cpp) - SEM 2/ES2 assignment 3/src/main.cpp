/*
Author: Vincent, Johnson
Bit operations part A
*/

#include <Arduino.h>
#include <stdint.h>

//Assigned PINS to masks.
#define LEDMASKD (1 << PD7)       // Mask for output LEDs
#define BTNMASKD (1 << PD5)       // button
#define BTNMASKDSWEEP (1 << PD2)  // button pull up
#define LEDMASKB (1 << PB5)       // builtin LED
#define PIN1_MASK (1 << PB1)      //LED 1 MASK
#define PIN2_MASK (1 << PB2)      //LED 2 MASK
#define PIN3_MASK (1 << PB3)      //LED 3 MASK
#define PIN4_MASK (1 << PB4)      //LED 4 MASK

//States for sweep A.
#define SweepATurnPB1 1 
#define SweepATurnPB2 2
#define SweepATurnPB3 3
#define SweepATurnPB4 4
#define SweepATurnPB3Again 5
#define SweepATurnPB2Again 6
#define startSweepA 1
#define EndOfSweepA 6

//States for sweep B.
#define SWEEPING_LED_MASK_CONSTANT_FOR_RESTARTING 0b0000000000001111  //binary value that is shifted to control LEDs.
#define EndOfMaskForSweepB 6
#define StartOfMaskForSweepB 0
#define OneStep 1

// Part A: Variables for button 1 .
const unsigned long BUTTON_INTERVAL_A = 40;
unsigned long debounceTimeA = 0;
bool buttonStateA = true;
bool lastButtonStateA = true;
bool buttonStateSwitchA = false;

// Part B: Variables for button 2 (PULL UP).
const unsigned long DEBOUNCE_INTERVAL_B = 40;
unsigned long debounceTimeB = 0;
bool buttonStateB = true;
bool lastButtonStateB = true;
bool buttonStateSwitchB = false;

//timers
unsigned long currentMillis = 0;              // current time
unsigned long lastTimeBlinking = 0;           // last time for blinking led
const unsigned long BLINKING_INTERVAL = 250;  // blinking interval of 1/4 second
bool ledBlinking = false;                     // switch state for the led
unsigned long lastTimeSweepA = 0;             // last time for states sweep A
const unsigned long SWEEPA_INTERVAL = 200;    // state change interval for sweep A     
int statesSweepA = 0;                         // variable to switch states of sweep A

//SweepB
bool remeberResetSweepB = false;                        // to Reset sweep B so it will begin from the start.
bool sweepBGoBack = false;                              // bool value to decide if sweep B should go from left to right or the opposite.
const uint16_t SWEEPB_MASK_16BIT = 0b0000000001111000;  // mask used to control the LEDs for sweep B. 
static uint16_t SWEEPING_LED_MASK = SWEEPING_LED_MASK_CONSTANT_FOR_RESTARTING;
static int counterBitShift = 0;                         // variable used as value to shift binary.
bool btnSweepStatePrev = false;


void setup() {
  DDRD = DDRD & ~BTNMASKD;        // set the pin to input for button 1.
  DDRD = DDRD & ~BTNMASKDSWEEP;   // set the pin to input for button 2.
  PORTD = PORTD | BTNMASKDSWEEP;  // to make button 2 a "PULL UP" button.

  DDRD = DDRD | LEDMASKD;         // set the pins to outputs for LEDs.
  DDRB = DDRB | LEDMASKB | PIN1_MASK | PIN2_MASK | PIN3_MASK | PIN4_MASK;   // set the pin to output for LEDs and Builtin LED.
}

/// @brief Function that toggles an LED on and off.
void externalLedBlink(){
  if(ledBlinking){
    PORTD = PORTD | LEDMASKD;   // LED ON (HIGH).
  } else{
    PORTD = PORTD & ~LEDMASKD;  // LED OFF (LOW).
  }
}

/// @brief function that changes the state of the builtIn LED based on the button state.
/// @param btnstate 
void btnLedOnOrOFF(bool btnState){
  if (!btnState){
    PORTB = PORTB & ~LEDMASKB;  // LED OFF (LOW).
  } else{
    PORTB = PORTB | LEDMASKB;   // LED ON (HIGH).
  }
}

/// @brief Function that debounces the button and returns the value of the debounced button.
/// @return Debounced button state.
bool buttonDebouncePartA(){
  bool reading = !(PIND & BTNMASKD);

  if (reading != lastButtonStateA) {
    debounceTimeA = millis();                                   // reset the debounce timer
  }
  if ((currentMillis - debounceTimeA) > BUTTON_INTERVAL_A) {    // check if interval has been passed.
    if (reading != buttonStateA) {
      buttonStateA = reading;
      
      buttonStateSwitchA = !buttonStateSwitchA;
    }
  }
  lastButtonStateA = reading;                                   // save the button state for next iteration.
  return buttonStateSwitchA;
}

/// @brief Function that performs sweep A. It does so By turning specific LEDs on and off depending on which state it is in.
/// @param statesSweepA 
void PerformSweepA(int statesSweepA){
  switch(statesSweepA) {
    case SweepATurnPB1:
      PORTB = (PORTB | PIN1_MASK) & ~PIN2_MASK; // Set PB 1 high and set PB 2 low
      break;
    case SweepATurnPB2:
      PORTB = (PORTB & ~PIN1_MASK) | PIN2_MASK; // Set PB 1 low and Set PB 2 high
      break;
    case SweepATurnPB3:
      PORTB = (PORTB & ~PIN2_MASK) | PIN3_MASK; // Set PB 2 low and PB 3 high
      break;
    case SweepATurnPB4:
      PORTB = (PORTB & ~PIN3_MASK) | PIN4_MASK; // Set PB 3 low and PB 4 high
      break;
    case SweepATurnPB3Again:
      PORTB = (PORTB & ~PIN4_MASK) | PIN3_MASK; // Set PB 4 low and PB 3 high
      break;
    case SweepATurnPB2Again:
      PORTB = (PORTB & ~PIN3_MASK) | PIN2_MASK; // Set PB 3 low and PB 2 high
      break;
    default:
      // default case
      break;
  }
}

/// @brief Function that turns off all LEDs.
void ledReset(){
  PORTB = PORTB & ~PIN1_MASK;
  PORTB = PORTB & ~PIN2_MASK;
  PORTB = PORTB & ~PIN3_MASK;
  PORTB = PORTB & ~PIN4_MASK;
}

/*
  Function that performs sweep B.
  It does this by Shifting a mask over a another mask. 
  The second mask controls which LEDs are on at that time and which are off.
*/
void PerformSweepB(){
  if (!remeberResetSweepB){   // resetting sweepB
    remeberResetSweepB = true;
    SWEEPING_LED_MASK = SWEEPING_LED_MASK_CONSTANT_FOR_RESTARTING;
    counterBitShift = 0;      // start from left to right
    sweepBGoBack = true; 
  }

  // Sweep B Mask :0b0000000001111000
  uint16_t LedChangeMaskOn = SWEEPB_MASK_16BIT & SWEEPING_LED_MASK; // mask to set value for the LEDs.
  LedChangeMaskOn = LedChangeMaskOn >> counterBitShift;             // shift the mask for next state.
  
  ledReset(); 
  PORTB = PORTB | (LedChangeMaskOn << OneStep);                     // turn the LEDs on or off based on mask value.
  
  if (sweepBGoBack){                                                // sweep goes from left to right.
    counterBitShift++;
    SWEEPING_LED_MASK = SWEEPING_LED_MASK << OneStep;
  } else{                                                           // sweep goes from right to left.
    counterBitShift--;
    SWEEPING_LED_MASK = SWEEPING_LED_MASK >> OneStep;
  }
  
  //used to switch the state that determines if sweep should go from left to right or opposite.
  if ((counterBitShift >= EndOfMaskForSweepB) || (counterBitShift == StartOfMaskForSweepB)) {
    sweepBGoBack = !sweepBGoBack;
  }
}

/// @brief Function that debounces the button and returns the value of the debounced button.
/// @return Debounced button state
bool buttonDebouncePartBPullUp(){
  bool readingPartB = !(PIND & BTNMASKDSWEEP);

  if (readingPartB != lastButtonStateB) {
    debounceTimeB = millis();                                       // reset the debounce timer.
  }
  
  if ((currentMillis - debounceTimeB) > DEBOUNCE_INTERVAL_B) {      // check if interval has been passed.
    if (readingPartB != buttonStateB) {
      buttonStateB = readingPartB;
      
      buttonStateSwitchB = !buttonStateSwitchB;
    }
  }
  buttonStateSwitchB = readingPartB;                                // save the button state for the next iteration.
  return buttonStateSwitchB;
}

void loop() {
  currentMillis = millis();

  // Part A
  externalLedBlink();

  if (currentMillis - lastTimeBlinking >= BLINKING_INTERVAL) {
    lastTimeBlinking = currentMillis; // Update the timer of the Blinking LED.
    ledBlinking = !ledBlinking;       // change LED state
  }

  buttonStateSwitchA = buttonDebouncePartA();
  btnLedOnOrOFF(buttonStateSwitchA);

  // Part B
  // read the button to determine if the program should be in sweep A or B.
  bool btnSweepState = buttonDebouncePartBPullUp();
  if (btnSweepStatePrev != btnSweepState){
    ledReset(); 
    btnSweepStatePrev = btnSweepState;
    statesSweepA = startSweepA;                               // start from 1 instead of any other states.
    remeberResetSweepB = false;                               // reset sweep B so it begins from the start when button is released.
  }

  if (currentMillis - lastTimeSweepA >= SWEEPA_INTERVAL) {
    lastTimeSweepA = currentMillis;                           // Update sweep A's Last timer.

    if (btnSweepState){                                       //Perform sweep A if button is pressed.
      PerformSweepA(statesSweepA);
      statesSweepA++;
      if (statesSweepA > EndOfSweepA){
        statesSweepA = startSweepA;
      }
    } else {                                                  // perform sweep B if button isn't pressed.
      PerformSweepB();
    }
  }
}