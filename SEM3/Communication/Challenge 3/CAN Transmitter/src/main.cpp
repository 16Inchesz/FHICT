#include <Arduino.h>
#include <SPI.h>
#include <mcp_can.h>

//PINS
#define SPICSPIN 10

//variables used
byte ledState = 0x01;
int currentState = 1;

//create can object
MCP_CAN CAN(SPICSPIN);

//buffer for sending messages.
byte data[1] = {ledState};

void setup()
{
    Serial.begin(9600);
    while (CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    Serial.println("CAN BUS Shield Init OK!");
    CAN.setMode(MCP_NORMAL);
}

    
void loop()
{
  // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  byte sndStat = CAN.sendMsgBuf(0x100, 0, 1, data);
  if(sndStat == CAN_OK){
    Serial.println("Message Sent Successfully!");
  } else {
    Serial.println("Error Sending Message...");
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //PART A: state machine for LED state
  // if (!currentState){
  //   currentState = !currentState;
  //   data[0] = 0x00;
  // } else {
  //   currentState = !currentState;
  //   data[0] = 0x01;
  // }
  // delay(1000);
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
