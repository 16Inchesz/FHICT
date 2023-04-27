#ifndef BME280_H
#define BME280_H

#include <Wire.h>


#define BME280_ADDRESS 0x76 
#define BME280_RESET_ADDRESS 0xE0
#define BME280_ID_ADDRESS 0xD0
#define BME280_CTRLHUM_ADDRESS 0xF2
#define BME280_CTRLMEAS_ADDRESS 0xF4
#define BME280_RESET_MESSAGE 0xB6

void WriteToAddress(uint8_t I2Caddress, uint8_t registerAddress, uint8_t message);

uint8_t ReadFromAddress(uint8_t I2Caddress, uint8_t address);

uint8_t BME280_GetID();

void BME280_Reset();

uint8_t BME280_CtrlHum();

void BME280_CtrlHum(uint8_t bitpattern);

uint8_t BME280_CtrlMeas();

void BME280_CtrlMeas(uint8_t bitpattern);

long BME280_ReadTemperature();

int BME280_ReadHumidity();

long BME280_ReadPressure();

#endif