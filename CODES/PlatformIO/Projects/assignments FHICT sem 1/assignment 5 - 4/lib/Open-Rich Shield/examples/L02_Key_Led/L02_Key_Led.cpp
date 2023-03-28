/*
 * Example Key Led.
 * Copyright Fontys 2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Date: 05/07/2019
 * Based on the Arduino Button example. Adapted for the Rich Shield.
 */

#include <Arduino.h>
#include <OpenRichShield.h>

const int PIN_BUTTON = 8; // The number of the KEY1 pin
const int PIN_LED = 4; // The Number of the red LED pin

int buttonState = 0; // keep track of the button state.

void setup()
{
    pinMode(PIN_LED, OUTPUT);
    // On the rich shield the buttons are connected without an external
    // pullup resistor, so tell the MCU to use an internal pullup
    pinMode(PIN_BUTTON, INPUT_PULLUP); 
}

void loop()
{
    // Read the state of the button
    buttonState = digitalRead(PIN_BUTTON);
    
    if (buttonState == LOW) {
        // turn the led on (the button is active LOW)
        digitalWrite(PIN_LED, HIGH);
    } else {
        // turn the led off.
        digitalWrite(PIN_LED, LOW);
    }
}
