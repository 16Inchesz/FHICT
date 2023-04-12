#include <stdio.h>
#include <stdint.h>


int main()
{
    
}

/*
    exercise 1 + 2

    uint8_t varA = 0b10110010;
    uint8_t varB = 0b00110101;
    uint8_t result;

    //result of And comparison
    result = varA & varB;
    printf("%02X\n", result);
    //result of OR comparison
    result = varA | varB;
    printf("%02X\n", result);
    //result of Xor comparison
    result = varA ^ varB;
    printf("%02X\n", result);
*/

/*
    exercise 3

    uint8_t varA = 0b11011010;
    uint8_t mask = 0b00000100;
    uint8_t result;

    //printing variable A into hexadecimal
    printf("%02X\n", varA);
    //printing variable A with B2 changed.
    result = varA | mask;
    printf("%02X\n", result);
*/

/*
    exercise 4

    uint8_t varA        = 0b10110010;
    uint8_t mask_b_4    = 0b10100010;
    uint8_t mask_b_2_4  = 0b10100110;
    uint8_t result;

    //printing variable A into hexadecimal 
    printf("%02X\n", varA);

    //printing variable A with b4 changed
    result = varA & mask_b_4;
    printf("%02X\n", result);

    //printing variable A with B2 + B4 changed
    result = varA | mask_b_2_4;
    printf("%02X\n", result);

    return 0;
*/

/*
    exercise 5

    uint32_t varA = 0xD7448EAB;
    uint16_t result; 

    //shifting the binary value by 10 to the right then printing result.
    result = varA >> 10;
    printf("%02X\n", result);
*/
