#ifndef ENCODER_H
#define ENCODER_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


/// @brief This function is an encoding algorithm for the input byte.
/// @param  inputByte
/// @param  encodedByteHigh*
/// @param  encodedByteLow*
/// @return Returns true on function success.
bool encodeByte(uint8_t, uint8_t*, uint8_t*);

/// @brief Function that calculates the parity bits for the nibble provided
/// @param  nibble
/// @return Returns the parity bits
uint8_t CalculateParity(uint8_t);
#endif