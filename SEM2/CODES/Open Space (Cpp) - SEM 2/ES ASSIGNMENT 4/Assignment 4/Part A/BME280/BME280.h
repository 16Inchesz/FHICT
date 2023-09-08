#pragma once
#ifndef BME280_H
#define BME280_H

#include "Wire.h"

#define BME280_ADDRESS 0x76 
#define BME280_RESET_ADDRESS 0xE0
#define BME280_RESET_MESSAGE 0xB6
#define BME280_ID_ADDRESS 0x60
#define BME280_CTRLHUM_ADDRESS 0xF2
#define BME280_CTRLMEAS_ADDRESS 0xF4
#define BME280_TEMPMSB_ADDRESS 0xFA
#define BME280_TEMPLSB_ADDRESS 0xFB
#define BME280_TEMPXLSB_ADDRESS 0xFC
#define BME280_HUMMSB_ADDRESS 0xFD
#define BME280_HUMLSB_ADDRESS 0xFE
#define BME280_PRESMSB_ADDRESS 0xF7
#define BME280_PRESLSB_ADDRESS 0xF8
#define BME280_PRESXLSB_ADDRESS 0xF9

class BME280
{
    private:
        long t_fine;
        /// @brief writes a byte to the specified register of the BME280
        /// @param I2Caddress 
        /// @param address 
        /// @param message 
        void WriteToAddress(uint8_t address, uint8_t message);

        /// @brief reads 1 byte from the specified register
        /// @param I2Caddress 
        /// @param address 
        /// @return the byte stored at the requested address 
        uint8_t ReadFromAddress(uint8_t address);

        /// @brief reads 2 bytes from the specified register
        /// @param address 
        /// @return two bytes from the address
        uint16_t Read16FromAddress(uint8_t address);
    public:

        bool begin();
        /// @brief gives the ID of the BME208 stored at the id address
        /// @return the requested ID
        uint8_t BME280_GetID();

        /// @brief resets the BME280 by writing reset message to the reset address
        void BME280_Reset();
        uint8_t BME280_CtrlHum();

        /// @brief sets humidity data acquisition option
        /// @param bitpattern 
        void BME280_CtrlHum(uint8_t bitpattern);
        uint8_t BME280_CtrlMeas();

        /// @brief activates changes to the ctrl_hum
        /// @param bitpattern 
        void BME280_CtrlMeas(uint8_t bitpattern);

        /// @brief reads temp from sensor 
        /// @return temp in C as float
        float BME280_ReadTemperature();

        /// @brief reads humidity from sensor
        /// @return humidity in % as float
        float BME280_ReadHumidity();

        /// @brief reads presure from sensor
        /// @return returns pressure in Pa as float
        float BME280_ReadPressure();
};
#endif