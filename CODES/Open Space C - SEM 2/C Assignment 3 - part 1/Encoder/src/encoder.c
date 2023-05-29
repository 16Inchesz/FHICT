#include "encoder.h"

uint8_t CalculateParity(uint8_t nibble){
    
    //calculate the data bit.
    uint8_t d3 = (nibble >> 3 ) & 0x0001;
    uint8_t d2 = (nibble >> 2) & 0x0001;
    uint8_t d1 = (nibble >> 1 ) & 0x0001;
    uint8_t d0 = nibble & 0x0001;

    //calculate parity bits. See hamming code logic circuit.
    uint8_t p2 = (d3 ^ d2) ^ d0;
    uint8_t p1 = (d2 ^ d1) ^ d0;
    uint8_t p0 = (d3 ^ d1) ^ d0;

    uint8_t result = (p2 << 2) | (p1 << 1) | p0;
    return result;
}

bool encodeByte(uint8_t *inputByte, uint8_t *encodedByteHigh, uint8_t *encodedByteLow){
    //NULL input pointers
    if (inputByte == NULL || encodedByteHigh == NULL || encodedByteLow == NULL){
        return false;
    }

    //high nibble: shift the input byte 4 to the left, other bits will be deleted.
    uint8_t highNibble = (*inputByte) >> 4;
    //low nibble: use AND operator to compare the right most bits with 0b00001111.
    uint8_t lowNibble = (*inputByte) & 0x0F;

    //parity bits
    uint8_t parityHigh = CalculateParity(highNibble);
    uint8_t parityLow = CalculateParity(lowNibble);

    *encodedByteHigh = (parityHigh << 4) | highNibble;
    *encodedByteLow = (parityLow << 4) | lowNibble;

    return true;
}