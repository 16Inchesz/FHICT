#ifndef ENCODER_H
#define ENCODER_H

#include <stdbool.h>
#include <stdint.h>

/// @brief This function is an encoding algorithm for the input byte.
/// @param  inputByte*
/// @param  encodedByteHigh*
/// @param  encodedByteLow*
/// @return returns true on functions success.
bool encodeByte(uint8_t*, uint8_t*, uint8_t*);

/// @brief Function that calculates the parity bits for the nibble provided
/// @param  nibble
/// @return returns the parity bits
uint8_t CalculateParity(uint8_t);
#endif