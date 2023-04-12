#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "testing.h"

void TestingFunction8(uint8_t result, uint8_t expectedResult){
    if (result == expectedResult){
        printf("\nTest for this function is a success\n");
    } else {
        printf("\nError. Testing failed\n");
    }
}

void TestingFunction16(uint16_t result, uint16_t expectedResult){
    if (result == expectedResult){
        printf("\nTest for this function is a success\n");
    } else {
        printf("\nError. Testing failed\n");
    }
}

void TestingFunctionMaskedByte(char mode[], uint8_t result, uint8_t expectedResult){
    if (result == expectedResult){
        printf("\nThe %s test for this function is a success\n", mode);
    } else {
        printf("\nError: Testing failed\n");
    }  
}
