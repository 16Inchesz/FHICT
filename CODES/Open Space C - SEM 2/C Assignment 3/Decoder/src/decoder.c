#include "decoder.h"

uint8_t CalculateParity(uint8_t nibble){
    //calculate the data bit.
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
    if (errorHigh){
        //calculate difference between calculated and transmitted parity bits.
        uint8_t diffHigh = parityHigh ^ (transmittedByteHigh >> 4);

        // find number of bits that are flipped.
        int flippedBits = 0;
        if ((diffHigh >> 2) & 0x01){
            flippedBits++;
        }
        if ((diffHigh >> 1) & 0x01){
            flippedBits++;
        }
        if (diffHigh & 0x01){
            flippedBits++;
        }

        //difference is 2 (1 corrupt data bit)
        if(flippedBits == 2){
            if ((diffHigh & 0x06) == 0x06){ //data bit 2 is corrupt (p1 + p2)
                highNibble ^= 0x04;
            } else if ((diffHigh & 0x05) == 0x05){  //data bit 3 is corrupt (p2 + p0)
                highNibble ^= 0x08;
            } else if ((diffHigh & 0x03) == 0x03){  //data bit 1 is corrupt (p0 + p1)
                highNibble ^= 0x02;
            }
        } else if (flippedBits == 3){   //data bit 0 is corrupt. (p0 + p1 + p2)
            highNibble ^= 0x01;
        }
    }

    if(errorLow){
        //calculate difference between calculated and transmitted parity bits.
        uint8_t diffLow = parityLow ^ (transmittedByteLow >> 4);    //use and operator.

        // find number of bits that are flipped.
        int flippedBits = 0;
        if ((diffLow >> 2) & 0x01){
            flippedBits++;
        }
        if ((diffLow >> 1) & 0x01){
            flippedBits++;
        }
        if (diffLow & 0x01){
            flippedBits++;
        }

        //difference is 2 (1 corrupt data bit)
        if(flippedBits == 2){
            if ((diffLow & 0x06) == 0x06){ //data bit 2 is corrupt (p1 + p2)
                lowNibble ^= 0x04;
            } else if ((diffLow & 0x05) == 0x05){  //data bit 3 is corrupt (p2 + p0)
                lowNibble ^= 0x08;
            } else if ((diffLow & 0x03) == 0x03){  //data bit 1 is corrupt (p0 + p1)
                lowNibble ^= 0x02;
            }
        } else if (flippedBits == 3){   //data bit 0 is corrupt. (p0 + p1 + p2)
            lowNibble ^= 0x01;
        }
    }

    *decodedByte = (highNibble << 4) | lowNibble;

    return true;
    
}