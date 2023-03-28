#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "pointer_bit_handler.h"


bool CombineNibblesToBytePointer(uint8_t low_nibble, uint8_t high_nibble, uint8_t* combinedNibble){
    if(combinedNibble == NULL){    //idiotproof
        return false;
    }
    *combinedNibble = (high_nibble << 4) | (low_nibble);       //shifts both high nibbles with a value of 4.
    return true;
}

bool SwapBytesInWordPointer(uint16_t word, uint16_t* swappedWord){
    if(swappedWord == NULL){    //idiotproof
        return false;
    }
    *swappedWord = ((word << 8) | (word >> 8)); //shift the provided word to get a new word.
    return true;
}


bool ConstructMaskForBytePointer(uint8_t size, uint8_t shift, uint8_t* constructedMask){
    if(constructedMask == NULL){    //idiotproof
        return false;
    }
    for (int i = 0; i < size; i++) {
        *constructedMask |= (1 << i); //shifts 1 to left with i. Or operator is to make sure nothing gets overwritten.
    }
    *constructedMask <<= shift; //shifts mask with value of shift.
    return true;
}

bool ApplyMaskToBytePointer(char mode[], uint8_t byte, uint8_t mask, uint8_t* maskedByte){   //could use the constructMask function to make mask here.
    if(maskedByte == NULL){    //idiotproof
        return false;
    }
    //check mode null
    *maskedByte = byte;
    if (strcmp(mode, "SET") == 0){
        *maskedByte |= mask;    //or operator; set the bits specified by mask to 1.
    } else if (strcmp(mode, "CLEAR") == 0){
        *maskedByte &= ~mask;   //& operator; clear bits specified by mask to 0.
    } else if (strcmp(mode, "FLIP") == 0){
        *maskedByte ^= mask;    //Xor operator; flip bits specified by mask. 
    }
    return true;
}

bool SwapBitsInBytePointer(uint8_t byte, uint8_t* swappedBits){
    if(swappedBits == NULL){    //idiotproof
        return false;
    }
    uint8_t oddMask = 0xAA;     // 10101010 in binary
    uint8_t evenMask = 0x55;    // 01010101 in binary
    
    uint8_t odd_bits = byte & oddMask;      //compares byte and oddMask with & operator and get odd bits.
    uint8_t even_bits = byte & evenMask;    //compares byte and evenMask with & operator to get even bits.
    
    //shifts both even and odd bits by 1 (i.e. [b1 - b0] => [b0 - b1]).
    odd_bits >>= 1;
    even_bits <<= 1;
    
    *swappedBits = odd_bits | even_bits; //compare them using the or operator (so it doesn't put anything to 0).
    return true;
}

