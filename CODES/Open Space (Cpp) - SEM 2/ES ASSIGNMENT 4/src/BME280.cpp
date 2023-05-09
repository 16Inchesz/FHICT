#include "BME280.h"

#define BME280_ADDRESS 0x76 // I2C address of the BME280 sensor

uint8_t BME280_GetID() {
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xD0); // Register address of chip ID
  Wire.endTransmission();
  Wire.requestFrom(BME280_ADDRESS, 1); // Read one byte
  return Wire.read(); // Return chip ID
}

void BME280_Reset() {
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xE0); // Register address of reset
  Wire.write(0xB6); // Reset value
  Wire.endTransmission();
}

uint8_t BME280_CtrlHum() {
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xF2); // Register address of control humidity
  Wire.endTransmission();
  Wire.requestFrom(BME280_ADDRESS, 1); // Read one byte
  return Wire.read(); // Return control humidity value
}

void BME280_CtrlHum(uint8_t bitpattern) {
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xF2); // Register address of control humidity
  Wire.write(bitpattern); // New value
  Wire.endTransmission();
}

uint8_t BME280_CtrlMeas() {
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xF4); // Register address of control measurement
  Wire.endTransmission();
  Wire.requestFrom(BME280_ADDRESS, 1); // Read one byte
  return Wire.read(); // Return control measurement value
}

void BME280_CtrlMeas(uint8_t bitpattern) {
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xF4); // Register address of control measurement
  Wire.write(bitpattern); // New value
  Wire.endTransmission();
}

long BME280_ReadTemperature()
{
  int adc_T = (readRegister(BME280_REGISTER_TEMPDATA_MSB) << 12) | (readRegister(BME280_REGISTER_TEMPDATA_LSB) << 4) | (readRegister(BME280_REGISTER_TEMPDATA_XLSB) >> 4);

  long var1, var2, T;
  var1 = ((((adc_T >> 3) - ((long)dig_T1 << 1))) * ((long)dig_T2)) >> 11;
  var2 = (((((adc_T >> 4) - ((long)dig_T1)) * ((adc_T >> 4) - ((long)dig_T1))) >> 12) * ((long)dig_T3)) >> 14;
  t_fine = var1 + var2;
  T = (t_fine * 5 + 128) >> 8;
  return T;
}

int BME280_ReadHumidity() {
  uint8_t buf[2];
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(BME280_HUMIDITY_MSB);
  Wire.endTransmission(false);
  Wire.requestFrom(BME280_I2C_ADDR, (uint8_t)2);
  buf[0] = Wire.read();
  buf[1] = Wire.read();

  int rawHumidity = (buf[0] << 8) | buf[1];

  int hum = (rawHumidity * (((int64_t)dig_H1 << 24) >> 20)) >> 12;
  if (hum > 100000) {
    hum = 100000;
  } else if (hum < 0) {
    hum = 0;
  }
  return hum;
}