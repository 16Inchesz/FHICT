/*
 * Rich shield example
 * Adapted from Rich Shield Example Code
 * Name:
 * Date: 07/02/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Version: 1.0
 */

#include <Arduino.h>
#include <OpenRichShield.h>

void setup()
{
}

void loop()
{
    // Show a number as an integer
    display.show(8173);
    delay(2000);
    
    // show a number
    display.show(-0);
    delay(2000);

    // Show a string (Supports the following chars:
    // 0-9,A-F,-,_,H,U,r
    display.show("1E4A");
    delay(2000);

    // show a number
    display.show(54);
    delay(2000);

    // show a number
    display.show(0);
    delay(2000);
    
     // show a number negative number
    display.show(-137);
    delay(2000);

    // show a real number
    display.show(-3.141f);
    delay(2000);
    
    // show a real number
    display.show(3.141f);
    delay(2000);

    // show a real number
    display.show(0.643f);
    delay(2000);

    // show a real number
    display.show(-0.495f);
    delay(2000);

    // show a real number 0
    display.show(-0.00f);
    delay(2000);

}
