/*
 * Rich shield example
 * Adapted from Rich Shield Example Code
 * Name: Temperature Display
 * Date: 07/03/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Version: 1.0
 */

#include <Arduino.h>
#include <OpenRichShield.h>

const int PIN_NTC = 15;
const int NTC_R25 = 10000; // the resistance of the NTC at 25'C is 10k ohm
const int NTC_MATERIAL_CONSTANT = 3950; // value provided by manufacturer

void setup()
{
}

float get_temperature()
{
    float temperature,resistance;
    int value;
    value = analogRead(PIN_NTC);
    resistance   = (float)value * NTC_R25/(1024 - value); // Calculate resistance
    /* Calculate the temperature according to the following formula. */
    temperature  = 1/(log(resistance/NTC_R25)/NTC_MATERIAL_CONSTANT+1/298.15)-273.15;
    return temperature;
}

void loop()
{
    float celcius;
    celcius = get_temperature();
    display.show(celcius);
    delay(1000);
}
