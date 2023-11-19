#include <Arduino.h>
#include <SPI.h>
#include <mcp_can.h>
#include <Wire.h>
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h"

//PINS
#define SPICSPIN 10

//constants
byte LEDsOff = 0x01;
byte blinkLeft = 0x02;
byte blinkRight = 0x03;
byte LEDsOn = 0x04;

int CANID = 0x100;

const int UP = 180;
const int DOWN = 0;
const int LEFT = 180;
const int RIGHT = 0;
const int CENTRE = 89;

//data variables
byte dataByte = 0x01;
int state = 1;

//create can and joystick objects
MCP_CAN CAN(SPICSPIN);
JOYSTICK joystick;

//buffer for sending messages.
byte data[1] = {dataByte};

void setup()
{
  Serial.begin(9600);
  while (CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ))
  {
      Serial.println("CAN BUS init Failed");
      delay(100);
  }
  Serial.println("CAN BUS Shield Init OK!");
  if(joystick.begin() == false)
  {
    Serial.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
    while(1);
  }
  CAN.setMode(MCP_NORMAL);
}

void loop() {
  int x = joystick.getHorizontal();
  int y = joystick.getVertical();

  //blinking left
  if  (x == LEFT)
  {
    data[0] = blinkLeft;
    CAN.sendMsgBuf(CANID, 0, 1, data);
  }
  
  //blinknig right
  if (x == RIGHT)
  {
    data[0] = blinkRight;
    CAN.sendMsgBuf(CANID, 0, 1, data);
  }

  //headlights on
  if  (y == UP) //up
  {
    data[0] = LEDsOn;
    CAN.sendMsgBuf(CANID, 0, 1, data);
  }

  //all LEDs off.
  if ((x == CENTRE && y == CENTRE) || y == DOWN){
    data[0] = LEDsOff;
    CAN.sendMsgBuf(CANID, 0, 1, data);
  }

  delay(200);
}
