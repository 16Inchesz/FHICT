#include <Arduino.h>
#include <SPI.h>
#include <mcp_can.h>

//PINS
#define SPICSPIN 10
#define LED1PIN 7
#define LED2PIN 6

//create CAN object
MCP_CAN CAN(SPICSPIN);

//variables for message handling
long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[1];
char msgString[128];

//LED variables
unsigned long currentTime = 0;
unsigned long previousTime = 0;
const long INTERVAL = 500;
bool ledstate = 0;

//function to blink an LED 
void BlinkLED(int ledPin){
  if (currentTime - previousTime >= INTERVAL){
    previousTime = currentTime;
    digitalWrite(ledPin, ledstate);
    ledstate = !ledstate;
  }
}

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
    Serial.print("Data: \t");
    Serial.print(rxBuf[0]);
    Serial.println();
    
    if (rxId == 0x100){ // correct ID.
      //part B: toggling different LED states using button
      switch (rxBuf[0])
      {
      case 1:
        //all LEDs off
        digitalWrite(LED1PIN, LOW);
        digitalWrite(LED2PIN, LOW);
        break;
      case 2:
        //left LED blink
        digitalWrite(LED2PIN, LOW);
        BlinkLED(LED1PIN);
        break;
      case 3:
        //right LED blink
        digitalWrite(LED1PIN, LOW);
        BlinkLED(LED2PIN);
        break;
      case 4:
        //both LEDS on
        digitalWrite(LED1PIN, HIGH);
        digitalWrite(LED2PIN, HIGH);
        break;
      default:
        Serial.println("ERROR: unrecognized state");
        break;
      }
    }
    else {
      Serial.print("error: incorrect ID\n");
    }
  }
}