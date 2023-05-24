#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/// @brief function that tests a bit in a byte depending on poosition
/// @param byte 
/// @param position 
/// @return return 0 if bit is not set and 1 if bit is set.
bool TestBitInByte(uint8_t byte, uint8_t position){
    uint8_t mask = 1 << position;
    bool testedBit = ((byte & mask) != 0);
    return testedBit;
}

int main(int argc, char const *argv[])
{
    printf("\nNumber of arguments: %d\n", argc);
	printf("Executable file: %s\n", argv[0]);
	printf("Name of input file: %s\n", argv[1]);

    FILE * inputFile = NULL;
    FILE * outputFile = NULL;
    uint8_t byte;

    //open files
    inputFile = fopen(argv[1], "rb");
    outputFile = fopen(argv[2], "wb");

    //idiot proof
    if (inputFile == NULL || outputFile == NULL){
        exit(EXIT_FAILURE);
        //does this need to return something? i.e. return 0;
    }

    //read byte from file
    while (fread(&byte, sizeof(byte), 1, inputFile) != EOF){
        //use testbit in byte function. to checks bits.
        //update byte if condition checks out.
        //write byte to output file.
    }

    
    //fgetc || fread 
    //fputc || fwrite
    //use test bit in byte function to check bits in position 6(0), 2(1) and 3(1).
    //if true flip(invert) bit1
    //write ever byte to output file.

    //close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
