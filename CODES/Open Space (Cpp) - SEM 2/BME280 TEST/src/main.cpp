#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

//bme object to be used later for initializing.
Adafruit_BME280 bme;

//Delay between measurements in millis
unsigned long current_time = 0;
unsigned long previous_time = 0;
const int BME_INTERVAL = 2000;

byte degree[8] =
    {
        0b00011,
        0b00011,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000};

/// @brief This function is to read and print out the values provided by the BME280 sensor.
void ShowSensorValues(){
  if ((current_time - previous_time) > BME_INTERVAL){
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println("*C");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println("%");

    Serial.println();
    previous_time = current_time;
  }
}

//The bme.begin function is to test to see if the bme is able to read. 
void setup() {
Serial.begin(9600);
  if (!bme.begin(0x76)){
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  current_time = millis();
  ShowSensorValues();
}