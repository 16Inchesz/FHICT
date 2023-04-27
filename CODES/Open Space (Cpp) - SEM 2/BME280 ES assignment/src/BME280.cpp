#include "BME280.h"

void WriteToAddress(uint8_t I2Caddress, uint8_t address, uint8_t message){
    Wire.beginTransmission(I2Caddress);
    Wire.write(address);
    Wire.write(message);
    Wire.endTransmission();
}

uint8_t ReadFromAddress(uint8_t I2Caddress, uint8_t registerAddress){
    Wire.beginTransmission(I2Caddress);
    Wire.write(registerAddress);
    Wire.endTransmission(false);
    Wire.requestFrom(I2Caddress, (uint8_t) 1);
    return Wire.read();
}

uint8_t BME280_GetID(){
    return ReadFromAddress(BME280_ADDRESS, BME280_ID);
}

void BME280_Reset(){
    WriteToAddress(BME280_ADDRESS, BME280_RESET, BME280_RESET_MESSAGE);
}



