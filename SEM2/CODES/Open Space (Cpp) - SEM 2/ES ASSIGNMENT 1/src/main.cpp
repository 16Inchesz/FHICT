/*
Author: Vincent, Johnson
Bit operations part A
*/

#include <Arduino.h>

#define LEDMASKD (1 << PD7) // assign the mask of the outputs of LEDs
#define BTNMASKD (1 << PD5) // button
#define BTNMASKDSWEEP (1 << PD2) // button
#define LEDMASKB (1 << PB5) // builtin LED

#define PIN1_MASK (1 << PB1)
#define PIN2_MASK (1 << PB2)
#define PIN3_MASK (1 << PB3)
#define PIN4_MASK (1 << PB4)



unsigned long currentMillis = 0;

unsigned long lastTimerValBlinking = 0; // timer millis for blinking led
unsigned long TimerPeriodBlinking = 250;
bool ledBlinking = false; // switch state for the led


unsigned long lastTimerValSweepA = 0; // timer millis for states sweep A
unsigned long TimerPeriodSweepA = 200;
int statesSweepA = 0;
int statesSweepB = 0;


void setup() {
  DDRC = DDRC & ~BTNMASKD;// & ~BTNMASKDSWEEP;  // set the pin to input for btn
 // PORTC = PORTC & ~BTNMASKD;// | BTNMASKDSWEEP;  // make the sweep button a pull up

  DDRD = DDRD | LEDMASKD;   // set the pins to outputs for LED
  DDRB = DDRB | LEDMASKB | PIN1_MASK | PIN2_MASK | PIN3_MASK | PIN4_MASK;   // set the pin to output Builtin LED

  Serial.begin(9600);
}

// ass 3 part A
void externalLedBlink(){
  if(ledBlinking){
    PORTD = PORTD | LEDMASKD;   // make pin High
  } else{
    PORTD = PORTD & ~LEDMASKD;  // make pin Low
  }
}
void btnLedOnOrOFF(bool btnstate){
  if (btnstate){
    PORTB = PORTB & ~LEDMASKB;  // make pin Low
  } else{
    PORTB = PORTB | LEDMASKB;   // make pin High
  }
}

// ass 3 part B
void sweepA(int statesSweepA){
  if(statesSweepA == 1){
    PORTB = (PORTB | PIN1_MASK) & ~PIN2_MASK; // Set PB 1 high and set PB 2 low
  } else if(statesSweepA == 2){
    PORTB = (PORTB & ~PIN1_MASK) | PIN2_MASK; // Set PB 1 low and Set PB 2 high
  } else if (statesSweepA == 3){
    PORTB = (PORTB & ~PIN2_MASK) | PIN3_MASK; // Set PB 2 low and  PB 3 high
  } else if (statesSweepA == 4){
    PORTB = (PORTB & ~PIN3_MASK) | PIN4_MASK; // Set PB 3 low and PB 4 high
  } else if (statesSweepA == 5){
    PORTB = (PORTB & ~PIN4_MASK) | PIN3_MASK; // Set PB 4 low and PB 3 high
  } else if (statesSweepA == 6){
    PORTB = (PORTB & ~PIN3_MASK) | PIN2_MASK; // Set PB 3 low and PB 2 high
  } 
}
void sweepB(int statesSweepB){
  if (statesSweepB == 1){
    PORTB = (PORTB | PIN1_MASK); 
  } else if (statesSweepB == 2){
    PORTB = (PORTB | PIN2_MASK);
  } else if (statesSweepB == 3){
    PORTB = (PORTB | PIN3_MASK);
  } else if (statesSweepB == 4){
    PORTB = (PORTB | PIN4_MASK);
  } else if (statesSweepB == 5){
    PORTB = (PORTB & ~PIN1_MASK);
  } else if (statesSweepB == 6){
    PORTB = (PORTB & ~PIN2_MASK);
  } else if (statesSweepB == 7){
    PORTB = (PORTB & ~PIN3_MASK);
  } else if (statesSweepB == 8){
    PORTB = (PORTB & ~PIN4_MASK);
  }
}


void loop() {
  
  currentMillis = millis();

  
  sweepA(statesSweepA);
  externalLedBlink(); // Toggle LED on/off


  // ass 3 part A
  if (currentMillis - lastTimerValBlinking >= TimerPeriodBlinking) {
    // Update the last timer tick time
    lastTimerValBlinking = currentMillis;
    ledBlinking = !ledBlinking; // change state
  }


  bool btnstate = !(PINC & BTNMASKD);
  btnLedOnOrOFF(btnstate);
  // end part A


  // ass 3 part B

  // end part B

  // bool btnSweepState = !(PINC & BTNMASKDSWEEP);
  // Serial.println(btnSweepState);


  if (currentMillis - lastTimerValSweepA >= TimerPeriodSweepA) {
    // Update the last timer tick time
    lastTimerValSweepA = currentMillis;

    // if (btnSweepState){
      statesSweepA++; // change state
      if (statesSweepA > 6){
        statesSweepA = 1;
      }
    // }
  }
}