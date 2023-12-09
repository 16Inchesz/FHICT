#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

#define SPICSPIN 10
#define LED1PIN 3
#define LED2PIN 4

//IDs
const long HIGHBEAM_ID = 0x200;
const byte ON = 0x03;
const byte OFF = 0x04;
//constants
const byte LENGTH = 1;

//can reading variables
long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[1];
char msgString[128]; 

//available states
enum State {
  BLINKING_LEFT,
  BLINKING_RIGHT,
  HIGH_BEAM_ON,
  HIGH_BEAM_OFF,
  LED_OFF
};
State currentState = LED_OFF;

//can object
MCP_CAN CAN(SPICSPIN);

void setup(){
  //serial
  Serial.begin(9600);
  //CAN initialize
  while (CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ)) {
    Serial.println("CAN BUS Init Failed");
    delay(100);
  }
  CAN.setMode(MCP_NORMAL);
  Serial.println("CAN BUS  Init OK!");
}

void loop(){
  //check if message has been received
  if(CAN_MSGAVAIL == CAN.checkReceive()) {
    //read & print the message received
    CAN.readMsgBuf(&rxId, &len, rxBuf);
    if ((len == LENGTH) && (rxId == HIGHBEAM_ID)){
      Serial.println("-----------------------------");
      Serial.print("Data from ID: \t");
      Serial.print(rxId);
      Serial.print(" with Data: ");
      Serial.print(rxBuf[0]);
      Serial.print(" - ");

      //message to HIGHBEAM device
      switch(rxBuf[0]){
        case HIGH_BEAM_ON:
          digitalWrite(LED1PIN, HIGH);
          digitalWrite(LED2PIN, HIGH);
          Serial.println("on");
          break;
        case HIGH_BEAM_OFF:
          digitalWrite(LED1PIN, LOW);
          digitalWrite(LED2PIN, LOW); 
          Serial.println("off");
          break;
        default:
          Serial.println("Error: Unrecognized state");
          break;
      }
    }
  }
}