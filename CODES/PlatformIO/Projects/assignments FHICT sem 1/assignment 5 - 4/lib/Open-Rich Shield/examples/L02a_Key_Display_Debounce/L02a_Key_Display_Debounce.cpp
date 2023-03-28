/*
 * Rich shield example
 * Adapted from Rich Shield Example Code
 * Name: Key Display
 * Date: 07/03/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Version: 1.0
 */

#include <Arduino.h>
#include <OpenRichShield.h>

const int PIN_KEY1 = 9;
const int PIN_KEY2 = 8;

const int BOUNCE_DELAY = 50; // in ms

int count = 0;
int oldcount = 0;

// The button inputs are reverse (high = released, low = pressed)
int lastkey1state = HIGH;
int lastkey2state = HIGH;
int key1state = HIGH;
int key2state = HIGH;
int lasttime = 0;

void setup()
{
    pinMode(PIN_KEY1, INPUT_PULLUP);
    pinMode(PIN_KEY2, INPUT_PULLUP);
    display.show(count);
}

int read_key()
{
    int key = 0;
    int key1 = digitalRead(PIN_KEY1);
    int key2 = digitalRead(PIN_KEY2);

    if (key1 != lastkey1state)
    {
        lasttime = millis();
    }
    if (key2 != lastkey2state)
    {
        lasttime = millis();
    }

    if (millis() - lasttime > BOUNCE_DELAY) {

        if (key1state != key1) {
                key1state = key1;
            if (lastkey1state == LOW)
                key = 1;
        } 
        if (key2state != key2) {
            key2state = key2;
            if (lastkey2state == LOW)
                key = 2;
        }
    }
    lastkey1state = key1;
    lastkey2state = key2;
    return key;
}

void loop()
{
    int key = read_key();

    if (key == 1)
        count++;
    else if (key == 2)
        count--;

    if (oldcount != count) {
        display.show(count);
        oldcount = count;
    }
}
