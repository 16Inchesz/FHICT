#ifndef TESTING_H
#define TESTING_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/// @brief function that, either, prints success if true or prints an error message if condition is false
/// @param  result
/// @param  expectedResult
void TestingFunction8(uint8_t, uint8_t);

/// @brief function that, either, prints success if true or prints an error message if condition is false
/// @param  result
/// @param  expectedResult
void TestingFunction16(uint16_t, uint16_t);

/// @brief function that will print out success or error depending on the provided mode.
/// @param mode
/// @param result
/// @param expectedResult
void TestingFunctionMaskedByte(char[], uint8_t, uint8_t);

#endif