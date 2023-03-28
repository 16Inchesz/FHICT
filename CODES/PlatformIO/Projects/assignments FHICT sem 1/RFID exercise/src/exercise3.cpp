//ICT & Technology, exercise 3, Johnson Domacasse, 08/12/2022
#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9
#define REDLED 2

unsigned long GetRFIDTag(byte scanData[]) {
  unsigned long tag = 0;
  for (int i = 0; i < 4; i++) {
    tag *= 256; // same as tag <<= 8;
    tag += scanData[i];
  }
  return tag;
}

MFRC522 rfid(SS_PIN, RST_PIN);
void setup() {
  Serial.begin(9600); // Init Serial
  SPI.begin();      // Init SPI bus
  rfid.PCD_Init();  // Init MFRC522
  pinMode(REDLED, OUTPUT);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }
  rfid.PICC_HaltA();      // Stop reading
  rfid.PCD_StopCrypto1(); // Exit comm.
  unsigned long tag = GetRFIDTag(rfid.uid.uidByte);
  Serial.println(tag);

  // added this bit of code below to check if each tag works seperately on their own.
  // despite also seeing there number in the serial monitor.
  if (tag == 2720885532){
    digitalWrite(REDLED, HIGH);
  } else if (tag == 1245929252){
    digitalWrite(REDLED, LOW);
  }
}