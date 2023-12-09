#include <Arduino.h>

#include <mcp_can.h>
#include <SPI.h>

#define SPICSPIN 10

MCP_CAN CAN(SPICSPIN);

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

byte data[1] = {0x00};

void loop()
{
  // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  byte sndStat = CAN.sendMsgBuf(0x100, 0, 1, data);
  if(sndStat == CAN_OK){
    Serial.println("Message Sent Successfully!");
  } else {
    Serial.println("Error Sending Message...");
  }
  delay(1000);   // send data per 100ms
}