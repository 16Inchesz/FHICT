#include "channel.h"

bool TransmitByte(uint8_t encodedByte, uint8_t *transmittedByte, int *FlippedBits){
    if (transmittedByte == NULL){
        return false;
    }

    //Flipping a random bit position
    int bitPosition = rand() % NUMBER_OF_BITS;
    *transmittedByte = encodedByte ^ (1 << bitPosition);

    //Update the amount bit position in the array.
    FlippedBits[bitPosition]++;

    return true;
}