#include <Arduino.h>
#include <SPI.h>
#include <mcp_can.h>

//PINS
#define SPICSPIN 10
#define BUTTONPIN 3

//constants
byte LEDsOff = 0x01;
byte blinkLeft = 0x02;
byte blinkRight = 0x03;
byte LEDsOn = 0x04;

//data variables
byte dataByte = 0x01;
int state = 1;

//button variables
const int DEBOUNCETIME = 10;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;

//create can object
MCP_CAN CAN(SPICSPIN);

//buffer for sending messages.
byte data[1] = {dataByte};

//Function to change the state with a button
void StateChangeButton();

void setup()
{
    pinMode(BUTTONPIN, INPUT);
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
  //Part B: state machine for different LED modes.
  StateChangeButton();
  switch (state)
  {
  case 1:
    dataByte = LEDsOff;
    break;
  case 2:
    dataByte = blinkLeft;
    break;
    case 3:
    dataByte = blinkRight;
    break;
  case 4:
    dataByte = LEDsOn;
    break;
  default:
    Serial.println("ERROR: unrecognized state");
    break;
  }

  //assign data
  data[0] = dataByte;

  // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  byte sndStat = CAN.sendMsgBuf(0x100, 0, 1, data);
  if(sndStat == CAN_OK){
    Serial.println("Message Sent Successfully!");
  } else {
    Serial.println("Error Sending Message...");
  }
  delay(1000);  
}

void StateChangeButton() {
  int buttonState = digitalRead(BUTTONPIN);
  unsigned long currentMillis = millis();
  if (currentMillis - lastDebounceTime >= DEBOUNCETIME) {
    if (buttonState != lastButtonState) {
      lastDebounceTime = currentMillis;
      if (buttonState == LOW) {
        Serial.println("Button Pressed");
        if (state == 4) {
          state = 1;
        } else {
          state++;
        }
      }
    }
  }
  lastButtonState = buttonState;
}
