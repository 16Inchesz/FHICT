#include "BME280.h"
#include "arduino.h"
#include "Wire.h"

bool BME280::begin() 
{
  Wire.begin();
  
  uint8_t id = ReadFromAddress(0xD0);
  if (id != 0x60)
    return false;

  WriteToAddress(0xF5, 0x00);
  WriteToAddress(0xF2, 0x01);
  WriteToAddress(0xF4, 0x25); 
  
  return true;
}

void BME280::WriteToAddress(uint8_t address, uint8_t message)
{
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(address);
  Wire.write(message);
  Wire.endTransmission();
}

uint8_t BME280::ReadFromAddress(uint8_t address)
{
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(address);
  Wire.endTransmission(false);
  Wire.requestFrom(BME280_ADDRESS, 1);
  return Wire.read();
}

uint16_t BME280::Read16FromAddress(uint8_t address)
{
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(address);
  Wire.endTransmission(false);
  Wire.requestFrom(BME280_ADDRESS, 2);
  uint16_t lsb = Wire.read();
  return (Wire.read() << 8) | lsb;
}

uint8_t BME280::BME280_GetID()
{
  return ReadFromAddress(BME280_ID_ADDRESS);
}

void BME280::BME280_Reset()
{
  WriteToAddress(BME280_RESET_ADDRESS, BME280_RESET_MESSAGE);
}

uint8_t BME280::BME280_CtrlHum()
{
  return ReadFromAddress(BME280_CTRLHUM_ADDRESS);
}

void BME280::BME280_CtrlHum(uint8_t bitpattern)
{
  WriteToAddress(BME280_CTRLHUM_ADDRESS, bitpattern);
}

uint8_t BME280::BME280_CtrlMeas()
{
  return ReadFromAddress(BME280_CTRLMEAS_ADDRESS);
}

void BME280::BME280_CtrlMeas(uint8_t bitpattern)
{
  WriteToAddress(BME280_CTRLMEAS_ADDRESS, bitpattern);
}

float BME280::BME280_ReadTemperature()
{
  int32_t adc_T = (Read16FromAddress(0xFA) << 12) | (ReadFromAddress(0xFB) << 4) | (ReadFromAddress(0xFC) >> 4);
  uint16_t dig_T1 = (ReadFromAddress(0x88) << 8) | ReadFromAddress(0x89);
  int16_t dig_T2 = (ReadFromAddress(0x8A) << 8) | ReadFromAddress(0x8B);
  int16_t dig_T3 = (ReadFromAddress(0x8C) << 8) | ReadFromAddress(0x8D);

  int32_t var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
  int32_t var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;
  int32_t t_fine = var1 + var2;
  
  float T = (t_fine * 5 + 128) >> 8;
  return (T / 100.0);
}

float BME280::BME280_ReadPressure() 
{
  int32_t adc_P = (Read16FromAddress(0xF7) << 12) | (ReadFromAddress(0xF8) << 4) | (ReadFromAddress(0xF9) >> 4);
  uint16_t dig_P1 = (ReadFromAddress(0x8E) << 8) | ReadFromAddress(0x8F);
  int16_t dig_P2 = (ReadFromAddress(0x90) << 8) | ReadFromAddress(0x91);
  int16_t dig_P3 = (ReadFromAddress(0x92) << 8) | ReadFromAddress(0x93);
  int16_t dig_P4 = (ReadFromAddress(0x94) << 8) | ReadFromAddress(0x95);
  int16_t dig_P5 = (ReadFromAddress(0x96) << 8) | ReadFromAddress(0x97);
  int16_t dig_P6 = (ReadFromAddress(0x98) << 8) | ReadFromAddress(0x99);
  int16_t dig_P7 = (ReadFromAddress(0x9A) << 8) | ReadFromAddress(0x9B);
  int16_t dig_P8 = (ReadFromAddress(0x9C) << 8) | ReadFromAddress(0x9D);
  int16_t dig_P9 = (ReadFromAddress(0x9E) << 8) | ReadFromAddress(0x9F);

  int64_t var1, var2, p;
  var1 = ((int64_t)t_fine) - 128000;
  var2 = var1 * var1 * (int64_t)dig_P6;
  var2 = var2 + ((var1 * (int64_t)dig_P5) << 17);
  var2 = var2 + (((int64_t)dig_P4) << 35);
  var1 = ((var1 * var1 * (int64_t)dig_P3) >> 8) + ((var1 * (int64_t)dig_P2) << 12);
  var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)dig_P1) >> 33;

  if (var1 == 0) {
    return 0;
  }

  p = 1048576 - adc_P;
  p = (((p << 31) - var2) * 3125) / var1;
  var1 = (((int64_t)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
  var2 = (((int64_t)dig_P8) * p) >> 19;

  p = ((p + var1 + var2) >> 8) + (((int64_t)dig_P7) << 4);
  return (float)p / 256.0;
}

float BME280::BME280_ReadHumidity() 
{
  int32_t adc_H = (ReadFromAddress(0xFD) << 8) | ReadFromAddress(0xFE);

  uint8_t dig_H1 = ReadFromAddress(0xA1);
  int16_t dig_H2 = Read16FromAddress(0xE1);
  uint8_t dig_H3 = ReadFromAddress(0xE3);
  int16_t dig_H4 = (ReadFromAddress(0xE4) << 4) | (ReadFromAddress(0xE5) & 0x0F);
  int16_t dig_H5 = (ReadFromAddress(0xE6) << 4) | ((ReadFromAddress(0xE5) >> 4) & 0x0F);
  int16_t dig_H6 = Read16FromAddress(0xE7);

  int32_t v_x1_u32r;
  v_x1_u32r = (t_fine - ((int32_t)76800));
  v_x1_u32r = (((((adc_H << 14) - (((int32_t)dig_H4) << 20) - (((int32_t)dig_H5) * v_x1_u32r)) +
                  ((int32_t)16384)) >>
                 15) *
                (((((((v_x1_u32r * ((int32_t)dig_H6)) >> 10) *
                      (((v_x1_u32r * ((int32_t)dig_H3)) >> 11) + ((int32_t)32768))) >>
                     10) +
                    ((int32_t)2097152)) *
                       ((int32_t)dig_H2) +
                   8192) >>
                  14));
  v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) *
                             ((int32_t)dig_H1)) >>
                            4));
  v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
  v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);

  float H = (v_x1_u32r >> 12) / 1024.0;
  return H;
}
