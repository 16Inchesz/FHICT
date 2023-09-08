#include <Arduino.h>
#include <Wire.h>

#define ADRESS 0x42
#define DELAY 500

byte x = 0; //data send to the slave
//for timer
long lastTime = 0; 

void setup()
{
    Wire.begin();
    Serial.begin(9600);
}

void loop()
{
    long now = millis();
    if (now >= (lastTime + DELAY)) //timer
    {
        Wire.beginTransmission(ADRESS);
        Wire.write(x);
        Wire.endTransmission();
        Wire.requestFrom(ADRESS, 1); //request only once every 0.5 sec
        x++; //increace x after every transmission
        lastTime = now;
    }

    while (Wire.available()) //check for messages constantly
    {
        byte input = Wire.read();
        Serial.println(input); 
    }
}
