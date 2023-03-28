#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "bit_handler.h"

//general; We can use an if statement to check if provided values are above or below asked parameter. return error message if true.

uint8_t CombineNibblesToByte(uint8_t lowNibble, uint8_t highNibble){    
    uint8_t result = (highNibble << 4) | (lowNibble);       //shifts both high and low nibbles with a value of 4.
    return result;
}

uint16_t SwapBytesInWord(uint16_t word){
    uint16_t swappedWord = ((word << 8) | (word >> 8)); //shift the provided word around to get a new word.
    return swappedWord;
}

uint8_t ConstructMaskForByte(uint8_t size, uint8_t shift){
    uint8_t constructedMask = 0;
    for (int i = 0; i < size; i++) {
        constructedMask |= (1 << i); //shifts 1 to left with i. Or operator is to make sure nothing gets overwritten.
    }
    constructedMask <<= shift; //shifts mask with value of shift.
    return constructedMask;
}

uint8_t ApplyMaskToByte(char mode[], uint8_t byte, uint8_t mask){   //could use the constructMask function to make mask here.
    uint8_t maskedByte = byte;
    if (strcmp(mode, "SET") == 0){
        maskedByte |= mask;    //or operator; set the bits specified by mask to 1.
    } else if (strcmp(mode, "CLEAR") == 0){
        maskedByte &= ~mask;   //& operator; clear bits specified by mask to 0.
    } else if (strcmp(mode, "FLIP") == 0){
        maskedByte ^= mask;    //Xor operator; flip bits specified by mask. 
    } else {
        return false;
    }
    return maskedByte;
}

bool TestBitInByte(uint8_t byte, uint8_t position){
    uint8_t mask = 1 << position;               //shift the bit to the position you want to test.
    bool testedBit = ((byte & mask) != 0);      //returns the 0 if tested bit isn't set and 1 if it is set. 
    return testedBit;
}

uint8_t CountOnesInByte(uint8_t byte){
    uint8_t count = 0;
    for (uint8_t position = 0; position < BYTESIZE ; position++){       //iterate through the byte.
        if (TestBitInByte(byte, position)){                             //use TestBitInByte to check wether bit is set or not.
            count++;
        }
    }
    return count;
}

uint8_t SwapBitsInByte(uint8_t byte){
    uint8_t oddMask = 0xAA;     // 10101010 in binary
    uint8_t evenMask = 0x55;    // 01010101 in binary
    
    uint8_t odd_bits = byte & oddMask;      //compares byte and oddMask with & operator to get ONLY the odd bits.
    uint8_t even_bits = byte & evenMask;    //compares byte and evenMask with & operator to get ONLY the even bits.
    
    //shifts both even and odd bits by 1 (i.e. [b1 - b0] => [b0 - b1]).
    odd_bits >>= 1;
    even_bits <<= 1;
    
    uint8_t swappedBits = odd_bits | even_bits; //compare them using the or operator (so it doesn't put anything to 0).
    return swappedBits;
}

