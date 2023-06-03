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

