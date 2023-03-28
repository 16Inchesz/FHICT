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

int count = 0;

void setup()
{
    pinMode(PIN_KEY1, INPUT_PULLUP);
    pinMode(PIN_KEY2, INPUT_PULLUP);
    display.show(count);
}

int read_key()
{
    int key1 = digitalRead(PIN_KEY1);
    int key2 = digitalRead(PIN_KEY2);

    if (key1 == LOW)
        return 1;

    if (key2 == LOW)
        return 2;

    return 0;
}

void loop()
{
    int key = read_key();

    if (key == 1)
        count++;
    else if (key == 2)
        count--;
    
    display.show(count);
    
    delay(50);
}
