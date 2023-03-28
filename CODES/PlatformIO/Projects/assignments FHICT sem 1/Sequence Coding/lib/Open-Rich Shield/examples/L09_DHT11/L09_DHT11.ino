/*
 * Rich shield example
 * Adapted from Rich Shield Example Code
 * Name:
 * Date: 07/06/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Version: 1.0
 */

#include "Display.h"
#include "DHT11.h"

void setup()
{
}

void loop()
{
    float humidity = DHT11.getHumidity();
    float temperature = DHT11.getTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Display.show("Err ");
    }
    else
    {
        Display.show(humidity));
        delay(2500);
        Display.show(temperature);
        delay(2500);
    }

}
