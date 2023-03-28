#ifndef BIT_HANDLER_H
#define BIT_HANDLER_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//constants for the bit_handler program.
#define BYTESIZE 8

/// @brief Function that combines two nibbles; One being high and the other low.
/// @param  low_nibble
/// @param  high_nibble
/// @return Returns "combinedNibbles" as a byte.
uint8_t CombineNibblesToByte(uint8_t, uint8_t);

/// @brief Function that swaps the bytes in the paramater, "word"
/// @param  word
/// @return Returns the "swapped_bytes".
uint16_t SwapBytesInWord(uint16_t);

/// @brief Function that creates an 8-bit mask with a given "size" and "shift".
/// @param  size 
/// @param  shift 
/// @return Returns the "8bit_mask"
uint8_t ConstructMaskForByte(uint8_t, uint8_t);

/// @brief Function that applies "mask" to "byte" depending on the set "mode" (Set, Clear, Flip).
/// @param  mode ("CLEAR", "SET", "FLIP")
/// @param  byte
/// @param  mask
/// @return Returns "masked_byte".
uint8_t ApplyMaskToByte(char[], uint8_t, uint8_t);

/// @brief Function that tests a specific bit in "byte".
/// @param  byte
/// @param  position
/// @return Returns the bool value of the tested bit (returns 1 if bit is set and 0 if bit isn't set)
bool TestBitInByte(uint8_t, uint8_t);

///@brief Function that returns the amount of set bits in "byte".
///@param byte
///@return Returns the number of set bits in "byte"
uint8_t CountOnesInByte(uint8_t);

/// @brief Function that swaps odd and even bits in "byte".
/// @param  byte
/// @return returns "swapped_bits".  
uint8_t SwapBitsInByte(uint8_t);

#endif