#include <Arduino.h>
#include <Wire.h>

#define DELAY 100
#define ADRESS 0x42

long lastTime = 0; //for timer
byte output = 0;

void setup() 
{
  Wire.begin(ADRESS);                
  Wire.onReceive(receiveEvent); 
  Wire.onRequest(requestEvent);
  Serial.begin(9600);           
}

void loop() {}


void receiveEvent(int howMany) //receive event from the arduino example "slave_receiver"
{
  byte input = NULL;
  while (Wire.available()) // not greater than one because the data is only one byte
  {
    input = Wire.read(); 
    Serial.print("input: "); //print the received data to serial monitor for debugging
    Serial.println(input);    
  }      
  if(input > 100)//data handeling
  {
    output = 2;
  }
  else
  {
    output = 4;
  } 
  Serial.print("output: ");//printing output data to serial monitor for debugging
  Serial.println(output);
}

void requestEvent()//on request event print the output value
{
  Wire.write(output); 
}

