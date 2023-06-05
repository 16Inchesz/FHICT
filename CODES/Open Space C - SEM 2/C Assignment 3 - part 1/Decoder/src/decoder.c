#include "decoder.h"

uint8_t CalculateParity(uint8_t nibble){
    
    //calculate the data bit.
    //Room for optimization
    uint8_t d3 = (nibble >> 3) & 0x01;
    uint8_t d2 = (nibble >> 2) & 0x01;
    uint8_t d1 = (nibble >> 1) & 0x01;
    uint8_t d0 = nibble & 0x01;

    //calculate parity bits. See hamming code logic circuit.
    uint8_t p2 = d3 ^ d2 ^ d0;
    uint8_t p1 = d2 ^ d1 ^ d0;
    uint8_t p0 = d3 ^ d1 ^ d0;
    
    uint8_t result = (p2 << 2) | (p1 << 1) | p0;
    return result;
}

bool decodeByte(uint8_t transmittedByteHigh, uint8_t transmittedByteLow, uint8_t *decodedByte){
    if (decodedByte == NULL){
        return false;
    }

    //Get the nibbles from the transmitted data.
    uint8_t highNibble = transmittedByteHigh & 0x0F;
    uint8_t lowNibble = transmittedByteLow & 0x0F;

    //Calculate parity bits for comparison.
    uint8_t parityHigh = CalculateParity(highNibble);
    uint8_t parityLow = CalculateParity(lowNibble);

    //Compare the parity bits of recently calculated and transmitted parity bits.
    bool errorHigh = (transmittedByteHigh >> 4) != parityHigh;
    bool errorLow = (transmittedByteLow >> 4) != parityLow;

    //correction algorithm.
    if (errorHigh && errorLow){ //and or or operator.
        //check if 2 or more parity bits are corrupt.
        //two or more parity bits corrupt i.e. data error.
        //determine the position and correct it.
        //easiliy done with circle
        //new high and low nibbles are corrected and assigned.
    }

    *decodedByte = (highNibble << 4) | lowNibble;

    return true;
    
}