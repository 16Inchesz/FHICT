#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

#define SPICSPIN 10
#define LED1PIN 3
#define LED2PIN 4

const long BLINK_ID = 0x100;

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[1];
char msgString[128];                        

unsigned long currentTime = 0;
unsigned long previousTime = 0;
const long INTERVAL = 500;
bool ledstate = 0;

void BlinkLED(int ledPin){
  if (currentTime - previousTime >= INTERVAL){
    previousTime = currentTime;
    digitalWrite(ledPin, ledstate);
    ledstate = !ledstate;
  }
}

MCP_CAN CAN(SPICSPIN);

void setup()
{
  Serial.begin(9600);
  pinMode(SPICSPIN, OUTPUT);
  pinMode(LED1PIN, OUTPUT);
  pinMode(LED2PIN, OUTPUT);

  while (CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ))
  {
    Serial.println("CAN BUS Init Failed");
    delay(100);
  }
  CAN.setMode(MCP_NORMAL);   // Set operation mode to normal so the MCP2515 sends acks to received data.

  Serial.println("CAN BUS  Init OK!");                            
}

void loop()
{
  currentTime = millis();

  if(CAN_MSGAVAIL == CAN.checkReceive())
  {
    //read & print the message received
    CAN.readMsgBuf(&rxId, &len, rxBuf);
    Serial.println("-----------------------------");
    Serial.print("Data from ID: \t");
    Serial.print(rxId);
    Serial.print(" with Data: ");
    Serial.print(rxBuf[0]);
    Serial.println();
  }
}