#ifndef DECODER_H
#define DECODER_H

#include <stdbool.h>
#include <stdint.h>

/// @brief This function is a decoding algorithm for the transmitted byte.
/// @param  transmittedByteHigh
/// @param  transmittedByteLow
/// @param  decodedByte*
/// @return Returns true on function success.
bool decodeByte(uint8_t, uint8_t, uint8_t*);

/// @brief Function that calculates the parity bits for the nibble provided
/// @param  nibble
/// @return Returns the parity bits
uint8_t CalculateParity(uint8_t);

/// @brief Function that tests a specific bit in "byte".
/// @param  byte
/// @param  position
/// @return Returns the bool value of the tested bit (returns 1 if bit is set and 0 if bit isn't set)
bool TestBitInByte(uint8_t, uint8_t);

#endif