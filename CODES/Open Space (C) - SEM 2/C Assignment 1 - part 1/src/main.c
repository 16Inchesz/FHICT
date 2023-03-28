#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "bit_handler.h"
#include "pointer_bit_handler.h"
#include "testing.h"

//can be placed in header file for cleaner code.
//byte (binary examples)
uint16_t word[] = {0xB46D, 0x4B2D, 0x7CA4};
uint8_t lowNibbles[] = {0x0D, 0x07, 0x06};
uint8_t highNibbles [] = {0x0F, 0x0E, 0x03};
uint8_t byte[] = {0b01011001, 0b01101101, 0b10001101};
uint8_t mask[] = {0b00010111, 0b01001010, 0b01110111};
uint8_t position[] = {3, 4, 2};
uint8_t size[] = {3, 2, 5};
uint8_t shift[] = {2, 3, 1};

//expected answers
uint16_t expectedWord[] = {0x6DB4, 0x2D4B, 0x7CA4};
uint8_t expectedConstructedMask[] = {0x1C, 0x18, 0x3E};
uint8_t expectedSetByte[] = {0x5F, 0x6F, 0xFF};
uint8_t expectedClearedByteByte[] = {0x48, 0x25, 0x88};
uint8_t expectedFLippedByte[] = {0x4E, 0x27, 0xFA};
uint8_t expectedTestedBit[] = {1, 0, 1};
uint8_t expectedCountsInByte[] = {4, 5, 4};
uint8_t expectedSwappedByte[] = {0xA6, 0x9E, 0x4E};
uint8_t expectedCombinedNibbles[] = {0xFD, 0xE7, 0x36}; 

int main()
{
    //------------------------------------------------------------------------------------------------------------
    //Test for combining Nibbles to a Byte. low nibble will be right while the high nibble will be to the left.
    uint8_t combinedWord = CombineNibblesToByte(lowNibbles[1], highNibbles[1]);
    TestingFunction8(combinedWord, expectedCombinedNibbles[1]);
    printf("the combined nibbles are: %02X\n", combinedWord); 
    //============================================================================================================
    uint8_t combinedWordPointer = 0;
    if (CombineNibblesToBytePointer(lowNibbles[1], highNibbles[1], &combinedWordPointer)){
        printf("the combined nibbles are: %02X\n", combinedWordPointer);
    } else {
        printf("Error: invalid combinedword pointer\n");
    }

    //------------------------------------------------------------------------------------------------------------
    //Test for swapping Bytes in a Word. From word([b3, b2, b1, b0] to swappedword[b1, bo, b3, b2]).
    uint16_t swappedWord = SwapBytesInWord(word[1]); 
    TestingFunction16(swappedWord, expectedWord[1]);
    printf("the swapped word is: %04X\n", swappedWord); 
    //============================================================================================================
    uint16_t swappedWordPointer = 0;
    if (SwapBytesInWordPointer(word[2], &swappedWordPointer)){    
        printf("the Swapped word is: %04X\n", swappedWordPointer);
    } else{
        printf("Error: invalid swappedword pointer");
    }

    //------------------------------------------------------------------------------------------------------------
    //Test for constructing a Mask for a Byte.
    uint8_t constructedMask = ConstructMaskForByte(size[2], shift[2]);   
    TestingFunction8(constructedMask, expectedConstructedMask[2]);
    printf("the hexadecimal value of the constructed mask is: %02X\n", constructedMask);
    //============================================================================================================
    uint8_t constructedMaskPointer = 0;
    //expected result is that you create mask by specifying the size(total 1's) and then shifting it with by an value to the left(shift)
    if(ConstructMaskForBytePointer(size[1], shift[1], &constructedMaskPointer)){
        printf("the hexadecimal value of the constructed mask is: %02X\n", constructedMaskPointer);
    } else{
        printf("ERROR: invalid constructedmask pointer");
    }

    //------------------------------------------------------------------------------------------------------------
    //Test for applying a Mask to a Byte depending on the set Mode. Result is you will have a new masked byte, depending on each mode.
    //SET ==> set bits according to mask; CLEAR ==> clear bits according to mask; FLIP ==> flip the bits according to mask
    uint8_t maskedByte = ApplyMaskToByte("CLEAR", byte[2], mask[2]);
    TestingFunctionMaskedByte("SET", maskedByte, expectedSetByte[2]);
    TestingFunctionMaskedByte("CLEAR", maskedByte, expectedClearedByteByte[2]);
    TestingFunctionMaskedByte("FLIP", maskedByte, expectedFLippedByte[2]);
    printf("the hexadecimal value of the masked byte is: %02X\n", maskedByte);
    //============================================================================================================
    uint8_t maskedBytePointer = 0;
    if(ApplyMaskToBytePointer("SET", byte[1], mask[1], &maskedBytePointer)){
        printf("the hexadecimal value of the masked byte is: %02X\n", maskedBytePointer);
    } else{
        printf("ERROR: invalid maskedbyte pointer");
    }
    
    //------------------------------------------------------------------------------------------------------------
    //Test to test a Bit in Byte with given position. The value of the set bit will be printed.
    bool testedBit = TestBitInByte(byte[2], position[2]); 
    TestingFunction8(testedBit, expectedTestedBit[2]);
    printf("this bit has a binary value of: %d\n", testedBit);

    //------------------------------------------------------------------------------------------------------------
    uint8_t countsInByte = CountOnesInByte(byte[0]);  
    TestingFunction8(countsInByte, expectedCountsInByte[0]);
    printf("the number of set bits is provided byte is: %d\n", countsInByte);
    //------------------------------------------------------------------------------------------------------------

    //test for swapping odd and even Bits in Byte.
    uint8_t swappedByte = SwapBitsInByte(byte[2]); 
    TestingFunction8(swappedByte, expectedSwappedByte [2]); 
    printf("the hexadecimal value of the new byte is: %02X\n", swappedByte);
    //============================================================================================================
    uint8_t swappedBytePointer = 0;
    //what expected is that result will go from byte[b7, b6, b5, b4, b3, b2, b1, b0] to swappedbyte[b6, b7, b4, b5, b2, b3, b0, b1]
    if(SwapBitsInBytePointer(byte[0], &swappedBytePointer)){
        printf("the hexadecimal value of the new byte is: %02X\n", swappedBytePointer);
    } else {
        printf("ERROR: invalid swappedbyte pointer");
    }
    //------------------------------------------------------------------------------------------------------------
    return 0;
}
