#include <Arduino.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

#define FANPIN 3
#define SEALEVELPRESSURE_HPA (1013.25)
unsigned long current_time = 0;
unsigned long previous_time = 0;
const float UPPER_TEMP = 24.5;
const float LOWER_TEMP = 23.5;

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

Adafruit_BME280 bme;

byte fanduty = 0;
void setFanSpeed(byte speed)
{
  // Determine the fan duty value.
  fanduty = map(speed, 0, 100, 0, 255);
  // Continues speed.
  analogWrite(FANPIN, fanduty);
}
void swingFan()
{
  // Swing the fan.
  analogWrite(FANPIN, 255);
  delay(45);
  // Continues speed.
  analogWrite(FANPIN, fanduty);
}

float temperature = 0;
const int BME_INTERVAL = 2000;
void bmeValues()
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

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println("hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println("m");

    Serial.println();
    previous_time = current_time;
  }
}

void setup()
{
  pinMode(FANPIN, OUTPUT);
  Serial.begin(9600);
  if (!bme.begin(0x76))
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

bool isFanOn = false;
void loop(){
  current_time = millis();
  bmeValues();
  if (temperature >= UPPER_TEMP){
    if (isFanOn == false){
      setFanSpeed(90);
      swingFan();
      isFanOn = true;
    }
  } 
  if (temperature <= LOWER_TEMP){
    if (isFanOn == true){
      setFanSpeed(0);
      swingFan();
      isFanOn = false;
    }
  }
} 