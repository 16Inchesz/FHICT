#include "arduino.h"
#include "BME280.h"
#include "Wire.h"

BME280 bme;


void setup()
{
    Serial.begin(115200);

    bme.begin();
}
void loop()
{
    Serial.print("Hum: ");
    Serial.println(bme.BME280_ReadHumidity());
    Serial.print("Temp: ");
    Serial.println(bme.BME280_ReadTemperature());
    Serial.print("Pres: ");
    Serial.println(bme.BME280_ReadPressure());
    delay(1000);
}