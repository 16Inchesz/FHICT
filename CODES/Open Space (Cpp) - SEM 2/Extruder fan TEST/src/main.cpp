#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

#define FANPIN 3

//bme object used to initialize the sensor.
Adafruit_BME280 bme;

//delay in between each reading
unsigned long current_time = 0;
unsigned long previous_time = 0;
const int BME_INTERVAL = 2000;

//hysteris.
const float UPPER_TEMP = 24.5;
const float LOWER_TEMP = 23.5;
float temperature = 0;

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


byte fanduty = 0;

/// @brief function to swing the fan at max speed to start it.
void swingFan(){
  // Swing the fan.
  analogWrite(FANPIN, 255);
  delay(45);
  // Continue speed.
  analogWrite(FANPIN, fanduty);
}

//function to set a speed for the fan after you have swung it.
void setFanSpeed(byte speed){
  // Determine the fanduty value.
  fanduty = map(speed, 0, 100, 0, 255);
  // Continue speed.
  analogWrite(FANPIN, fanduty);
}

/// @brief This function reads and displays the values from the BME280 sensors. It also returns temperature for the fan.
float ReadBMEValues()
{
  temperature = bme.readTemperature(); // read temperature for fan
  if ((current_time - previous_time) > BME_INTERVAL)
  {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println("*C");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println("%");

    Serial.println();
    previous_time = current_time;
  }
  return temperature;
}

bool isFanOn = false;
/// @brief this function Turns the fan on and off according to the temperature..
void SwitchStatesFan(){
  if (temperature >= UPPER_TEMP){
    if (isFanOn == false){
      setFanSpeed(90);
      swingFan();
      isFanOn = true;
      Serial.println("The fan is on.");
    }
  } 
  if (temperature <= LOWER_TEMP){
    if (isFanOn == true){
      setFanSpeed(0);
      swingFan();
      isFanOn = false;
      Serial.println("The fan is off.");
    }
  }
}
//Check if the BME280 sensor is detected, else, display an error message.
void setup(){
  pinMode(FANPIN, OUTPUT);
  Serial.begin(9600);
  if (!bme.begin(0x76))
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop(){
  current_time = millis();
  ReadBMEValues();
  SwitchStatesFan();
} 