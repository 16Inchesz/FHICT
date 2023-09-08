#include <Wire.h>

#define SLAVE_ADD 0x50
#define VALUEA 0x21
#define VALUEB 0x22
#define MIN_ADD 0x23
#define MAX_ADD 0x24

byte INA, INB, Min, Max, Data = 0, request = 0;
int targetRegister, prevRegister;

void slave_init();
void receiveEvent(int);
void requestEvent();

void setup() {
  slave_init();
}

void loop() {
  switch (targetRegister) //state machine works based on the register send by the master
  {
    case VALUEA:
      if (prevRegister != targetRegister) {
        INA = Data;
        prevRegister = targetRegister;
      }
      break;
    case VALUEB:
      if (prevRegister != targetRegister) {
        INB = Data;
        prevRegister = targetRegister;
      }
      break;
    case MIN_ADD:
      if (prevRegister != targetRegister) {
        Min = min(INA, INB);
        prevRegister = targetRegister;

      }
      break;
    case MAX_ADD:
      if (prevRegister != targetRegister) {
        Max = max(INA, INB);
        prevRegister = targetRegister;
      }
      break;
    default:
      Serial.println("Not a Registered Address for Slave");
      break;
  }
}

//initializes slave: 
    //begins the I2C
    //sets the onreceive and onrequest to do receive event and request event
//to be run in the setup()
void slave_init() 
{
  Wire.begin(SLAVE_ADD);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  prevRegister = 0;
  Serial.begin(9600);
  Serial.println("Slave Online\n");
}


//on receive: read the first byte as register, and the second byte as the data if there is any
void receiveEvent(int howMany) 
{
  while (Wire.available()) 
  {
    targetRegister = Wire.read();
    if (howMany > 1) 
    {
      Data = Wire.read();
    }
  }
}

//writes the value requested (based on the send register) to the master
void requestEvent() 
{
  Wire.write(INA);
  Wire.write(INB);
  Wire.write(Min);
  Wire.write(Max);
}
