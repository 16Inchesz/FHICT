#include "Arduino.h"
#include "Wire.h"
#include "BME280.h"

#define SLAVEADRESS 0x50
#define DELAY 5000
#define DELAYMINMAX 5000
#define MINADRESS 0x23
#define MAXADRESS 0x24
#define AADRESS 0x21
#define BADRESS 0x22

BME280 bme;

long lastTimeA = 0;
char inputData;

void writeValue(int);
void requestValue();
void calcMinMax();

void setup()
{
  Wire.begin();
  bme.begin();
  Serial.begin(115200);
}

void loop()
{
  long now = millis();
  if (now >= (lastTimeA + DELAY)) //timer 
  {
    lastTimeA = now;


    writeValue(BADRESS);
    writeValue(AADRESS);
    calcMinMax();
    requestValue();
    
    Serial.print("Hum: ");
    Serial.println(bme.BME280_ReadHumidity());
    Serial.print("Temp: ");
    Serial.println(bme.BME280_ReadTemperature());
    Serial.print("Pres: ");
    Serial.println(bme.BME280_ReadPressure());
  }
}

//writes a random value between 0 and 255 to the specified register 
//and prints the value either A or B based on the adress
void writeValue(int adress)
{
    byte x = rand() % 255;
    Wire.beginTransmission(SLAVEADRESS);
    Wire.write(adress);
    Wire.write(x);
    Wire.endTransmission();
    if(adress == AADRESS)
      Serial.print("A is now ");
    else
      Serial.print("B is now ");
    Serial.println(x);
}

//requests 4 bytes (A, B, Min, Max) from the slave and prints them
void requestValue()
{
    Wire.requestFrom(SLAVEADRESS, 4);
    byte a = Wire.read();
    byte b = Wire.read();
    byte inputMin = Wire.read();
    byte inputMax = Wire.read();
    Serial.print("A: ");
    Serial.println(a);
    Serial.print("B: ");
    Serial.println(b);
    Serial.print("Min: ");
    Serial.println(inputMin);
    Serial.print("Max: ");
    Serial.println(inputMax);
}

//writes the min and max adress to slave to trigger the min, max calculation
void calcMinMax()
{
    Wire.beginTransmission(SLAVEADRESS);
    Wire.write(MINADRESS);
    Wire.endTransmission();
    Wire.beginTransmission(SLAVEADRESS);
    Wire.write(MAXADRESS);
    Wire.endTransmission();
}
