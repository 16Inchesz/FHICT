#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

#define SPICSPIN 10
#define LED1PIN 3
#define LED2PIN 4

//IDs
const long BLINKING_ID = 0x100;

//constants
const byte LENGTH = 1;
const byte LEFT = 0x01;
const byte RIGHT = 0x02;
const byte OFF = 0x04;

//can reading variables
long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[1];
char msgString[128];                        

//blinking variables
bool blinkingLeft = false;
bool blinkingRight = false;
unsigned long lastBlinkTime = 0;
const long BLINK_INTERVAL = 500;
bool led1State = LOW;
bool led2State = LOW;

void BlinkLED();

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
  if(CAN_MSGAVAIL == CAN.checkReceive()) {
    //read & print the message received
    CAN.readMsgBuf(&rxId, &len, rxBuf);
    if ((len == LENGTH) && (rxId == BLINKING_ID)){ 
      Serial.println("-----------------------------");
      Serial.print("Data from ID: \t");
      Serial.print(rxId);
      Serial.print(" with Data: ");
      Serial.print(rxBuf[0]);
      Serial.print(" - ");
      
      switch (rxBuf[0]) {
        case LEFT:
          //left LED blink
          digitalWrite(LED2PIN, LOW);
          blinkingLeft = true;
          Serial.println("LEFT");
          break;
        case RIGHT:
          //right LED blink
          digitalWrite(LED1PIN, LOW);
          blinkingRight = true;
          Serial.println("RIGHT");
          break;
        case OFF:
          //all LEDs off
          digitalWrite(LED1PIN, LOW);
          digitalWrite(LED2PIN, LOW);
          blinkingLeft = false;
          blinkingRight = false;
          Serial.println("OFF");
          break;
        default:
          Serial.println("ERROR: unrecognized state");
          break;
      }
    }
  }
  BlinkLED();
}

void BlinkLED(){
  unsigned long currentTime = millis();

  //blinking left LED
  if (blinkingLeft && (currentTime - lastBlinkTime >= BLINK_INTERVAL)) {
    lastBlinkTime = currentTime;
    led1State = !led1State;
    digitalWrite(LED1PIN, led1State);
  }

  //blinking right LED
  if (blinkingRight && (currentTime - lastBlinkTime >= BLINK_INTERVAL)) {
    lastBlinkTime = currentTime;
    led2State = !led2State;
    digitalWrite(LED2PIN, led2State);
  }
}