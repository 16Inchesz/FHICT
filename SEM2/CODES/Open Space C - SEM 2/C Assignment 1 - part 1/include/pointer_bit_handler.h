#ifndef POINTER_BIT_HANDLER_H
#define POINTER_BIT_HANDLER_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//constants for the bit_handler program.
#define BYTESIZE 8

/// @brief Function that combines two nibbles; One being high and the other low.
/// @param  low_nibble
/// @param  high_nibble
/// @param  combinedNibblePointer
/// @return Returns combinedNibbles if true.
bool CombineNibblesToBytePointer(uint8_t, uint8_t, uint8_t*);

/// @brief Function that swaps the bytes in the paramater, "word"
/// @param  word
/// @param  SwappedWordPointer
/// @return Returns the swappedBytes if true.
bool SwapBytesInWordPointer(uint16_t, uint16_t*);

/// @brief Function that creates an 8-bit mask with a given "size" and "shift".
/// @param  size 
/// @param  shift 
/// @param  ConstructedMaskPointer
/// @return Returns the constructedMask if true
bool ConstructMaskForBytePointer(uint8_t, uint8_t, uint8_t*);

/// @brief Function that applies "mask" to "byte" depending on the set "mode" (Set, Clear, Flip).
/// @param  mode ("CLEAR", "SET", "FLIP")
/// @param  byte
/// @param  mask
/// @param  MaskedBytePointer
/// @return Returns maskedByte if true
bool ApplyMaskToBytePointer(char[], uint8_t, uint8_t, uint8_t*);

/// @brief Function that swaps odd and even bits in "byte".
/// @param  byte
/// @return returns swappedBits if true.
/// @param  SwappedBitsPointer
bool SwapBitsInBytePointer(uint8_t, uint8_t*);

#endif