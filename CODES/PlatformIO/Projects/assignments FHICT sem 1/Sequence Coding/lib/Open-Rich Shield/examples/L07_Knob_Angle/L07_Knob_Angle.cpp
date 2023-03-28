/*
 * Rich shield example
 * Adapted from Rich Shield Example Code
 * Name:
 * Date: 07/05/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Version: 1.0
 */

#include <Arduino.h>
#include <OpenRichShield.h>

const int PIN_POTMETER = 14;

// the  maximum angle in degrees of the potmeter 0-280
const int MAX_ANGLE = 280;

void setup()
{
    pinMode(PIN_POTMETER,INPUT);
}

int get_knob_angle()
{
    int sensor_value = analogRead(PIN_POTMETER);
    int angle;
    // map is an Arduino library function.
    // it maps one range to another range.
    angle = map(sensor_value, 0, 1023, 0, MAX_ANGLE);

    return angle;
}

void loop()
{

    int angle;
    angle = get_knob_angle();
    display.show(angle);
    delay(500);
}
