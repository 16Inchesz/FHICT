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

#endif