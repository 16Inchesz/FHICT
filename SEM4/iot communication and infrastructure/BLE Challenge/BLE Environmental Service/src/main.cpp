#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include "DHTesp.h"

#define DHTPIN 19
#define BLE_SERVER_NAME "Environmental service"
#define SERVICE_UUID (BLEUUID((uint16_t)0x181A))  //environmental service UUID

BLECharacteristic *temperatureCharacteristic = nullptr;
BLECharacteristic *humidityCharacteristic = nullptr;

DHTesp dht;

bool deviceConnected = false;
class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
    Serial.println("Device Connected");
  };
  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
    Serial.println("Device Disconnected");
  }
};

void setup() {
  Serial.begin(115200);
  dht.setup(DHTPIN, DHTesp::DHT22);

  BLEDevice::init(BLE_SERVER_NAME);
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *bmeService = pServer->createService(SERVICE_UUID);

  temperatureCharacteristic = bmeService->createCharacteristic(
                                                  BLEUUID((uint16_t)0x2A6E),
                                                  BLECharacteristic::PROPERTY_NOTIFY
                                                  );
  
  humidityCharacteristic = bmeService->createCharacteristic(
                                                  BLEUUID((uint16_t)0x2A6F),
                                                  BLECharacteristic::PROPERTY_NOTIFY
                                                  );                                                  
  bmeService->start();
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}


void loop() {
  if (deviceConnected) {
    float temp = dht.getTemperature();
    float humid = dht.getHumidity();

    uint16_t temperature = (uint16_t)temp;
    temperatureCharacteristic->setValue(temperature);
    temperatureCharacteristic->notify();
    Serial.print("Temperature Celsius: ");
    Serial.print(temp);
    Serial.println(" ºC");

    uint16_t humidity = (uint16_t)humid;
    humidityCharacteristic->setValue(humidity);
    humidityCharacteristic->notify(); 
    Serial.print("Humidity: ");
    Serial.print(humid);
    Serial.println(" %");

    delay(5000);  
  }
}
