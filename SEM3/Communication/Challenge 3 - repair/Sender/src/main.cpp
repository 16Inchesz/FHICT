#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

//Pins
#define SPICSPIN 10
#define BUTTON1PIN 2
#define BUTTON2PIN 3
#define BUTTON3PIN 4
#define BUTTON4PIN 5

//IDs
const long BLINKING_ID = 0x100;
const long HIGHBEAM_ID = 0x200;

//constants
const byte LENGHT = 1;
const unsigned long DEBOUNCE_DELAY = 40;
const byte LEFT = 0x01;
const byte RIGHT = 0x02;
const byte ON = 0x03;
const byte OFF = 0x04;

//button variables
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;
int currentButtonState1;
int currentButtonState2;
int currentButtonState3;
int currentButtonState4;

//available states
enum State {
  BLINKING_LEFT,
  BLINKING_RIGHT,
  HIGH_BEAM_ON,
  HIGH_BEAM_OFF,
  LED_OFF
};
State currentState = LED_OFF;
State previousState = LED_OFF;

//can object
MCP_CAN CAN(SPICSPIN);

/// @brief Function to read the button input and update the state accordingly.
void UpdateState();

/// @brief Function to update 
void SendMessage();

/// @brief Debounce functions for each button
bool DebounceButton1();
bool DebounceButton2();
bool DebounceButton3();
bool DebounceButton4();

void setup() {
  //serial
  Serial.begin(9600);
  //pinmodes
  pinMode(BUTTON1PIN, INPUT);
  pinMode(BUTTON2PIN, INPUT);
  pinMode(BUTTON3PIN, INPUT);
  pinMode(BUTTON4PIN, INPUT);
  //CAN initialize
  while (CAN_OK != CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ)) {
      Serial.println("CAN BUS init Failed");
      delay(100);
  }
  CAN.setMode(MCP_NORMAL);
  Serial.println("CAN BUS Shield Init OK!");
}

void loop() {
  UpdateState();
  SendMessage();
}

//-------------------------------------------------------------------------------------------
void UpdateState() {
  if (DebounceButton1() == LOW) {
    currentState = BLINKING_LEFT;
  } else if (DebounceButton2() == LOW) {
    currentState = BLINKING_RIGHT;
  } else if (DebounceButton3() == LOW) {
    currentState = HIGH_BEAM_ON;
  } else if (DebounceButton4() == LOW) {
    currentState = HIGH_BEAM_OFF;
  } else {
    currentState = LED_OFF;
  }
}

void SendMessage() {
  //spam guard.
  if (currentState != previousState) {
    byte data[1] = {0};
    byte sndStat;

    //assign and send the correct message
    switch (currentState) {
      case BLINKING_LEFT:
        data[0] = {LEFT};
        sndStat = CAN.sendMsgBuf(BLINKING_ID, 0, LENGHT, data);
        break;
      case BLINKING_RIGHT:
        data[0] = {RIGHT};
        sndStat = CAN.sendMsgBuf(BLINKING_ID, 0, LENGHT, data);
        break;
      case HIGH_BEAM_ON:
        data[0] = {ON};
        sndStat = CAN.sendMsgBuf(HIGHBEAM_ID, 0, LENGHT, data);
        break;
      case HIGH_BEAM_OFF:
        data[0] = {OFF};
        sndStat = CAN.sendMsgBuf(HIGHBEAM_ID, 0, LENGHT, data);
        break;
      case LED_OFF:
        data[0] = {OFF};
        sndStat = CAN.sendMsgBuf(BLINKING_ID, 0, LENGHT, data);
        break;
      default:
        Serial.println("error unknown command");
        break;
    }

    if (sndStat == CAN_OK) {
      Serial.println("Message Sent Successfully!");
    } else {
      Serial.println("Error Sending Message...");
    }

    //update the state to avoid spamming.
    previousState = currentState; 
  }
}

//-------------------------------------------------------------------------------------------------
bool DebounceButton1() {
  int buttonState = digitalRead(BUTTON1PIN);
  if (buttonState != currentButtonState1) {
    lastDebounceTime1 = millis();
  }
  if ((millis() - lastDebounceTime1) > DEBOUNCE_DELAY) {
    currentButtonState1 = buttonState;
    return true;
  }
  return false;
}

bool DebounceButton2() {
  int buttonState = digitalRead(BUTTON2PIN);
  if (buttonState != currentButtonState2) {
    lastDebounceTime2 = millis();
  }
  if ((millis() - lastDebounceTime2) > DEBOUNCE_DELAY) {
    currentButtonState2 = buttonState;
    return true;
  }
  return false;
}

bool DebounceButton3() {
  int buttonState = digitalRead(BUTTON3PIN);
  if (buttonState != currentButtonState3) {
    lastDebounceTime3 = millis();
  }
  if ((millis() - lastDebounceTime3) > DEBOUNCE_DELAY) {
    currentButtonState3 = buttonState;
    return true;
  }
  return false;
}

bool DebounceButton4() {
  int buttonState = digitalRead(BUTTON4PIN);
  if (buttonState != currentButtonState4) {
    lastDebounceTime4 = millis();
  }
  if ((millis() - lastDebounceTime4) > DEBOUNCE_DELAY) {
    currentButtonState4 = buttonState;
    return true;
  }
  return false;
}