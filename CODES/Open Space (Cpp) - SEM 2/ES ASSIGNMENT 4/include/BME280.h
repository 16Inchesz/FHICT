#ifndef BME280_H
#define BME280_H

#include "Wire.h"

#define BME280_ADDRESS 0x76 
#define BME280_RESET 0xE0
#define BME280_RESET_MESSAGE 0xB6
#define BME280_ID 0x60

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