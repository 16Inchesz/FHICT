/*
 * Rich shield example
 * Adapted from Rich Shield Example Code
 * Fontys University of Applied Science
 * Name: LightSensor
 * Date: 07/01/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Version: 1.0
 */

#include <Arduino.h>
#include <OpenRichShield.h>

const int PIN_LDR = 16;

void setup()
{
    Serial.begin(9600);
    pinMode(PIN_LDR, INPUT);
}

void loop()
{
    // read the analog value
    int sensorValue = analogRead(PIN_LDR);
    float resistance_sensor;
    // and convert to resistance in Kohms
    resistance_sensor=(float)(1023-sensorValue)*10/sensorValue;

    Serial.print("The resistance of the light sensor is: ");
    Serial.print(resistance_sensor, 1);
    Serial.println(" KOhm");

    // convert the resitance to Lux
    float lux;
    lux = 325 * pow(resistance_sensor, -1.4);

    display.show(lux/1000);

    Serial.print("Illuminance is almost ");
    Serial.print(lux/1000, 1);
    Serial.println(" Kilo lux");
    delay(1000);

}
