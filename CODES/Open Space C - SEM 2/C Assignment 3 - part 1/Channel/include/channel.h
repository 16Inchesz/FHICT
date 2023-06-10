#ifndef CHANNEL_H
#define CHANNEL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_BITS 8

/// @brief This function acts as the bit flipping algorithm for the encoded byte.
/// @param  encodedByte
/// @param  transmittedByte*
/// @param  FlippedBits array to keep track of all the bit flips.
/// @return returns true on function success
bool TransmitByte(uint8_t, uint8_t*, int*);

#endif