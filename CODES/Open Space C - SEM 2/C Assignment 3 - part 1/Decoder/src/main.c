#include <stdio.h>
#include <stdlib.h>
#include "decoder.h"

int main(int argc, char const *argv[])
{
    //variables
    FILE * inputFile = NULL;
    FILE * outputFile = NULL;

    // Variables for decoding
    uint8_t transmittedByteHigh;
    uint8_t transmittedByteLow;
    uint8_t decodedByte;

    printf("\nNumber of arguments: %d\n", argc);
	printf("Executable file: %s\n", argv[0]);
	printf("Name of input file: %s\n", argv[1]);
    printf("Name of output file: %s\n\n", argv[2]);

    //open files.
    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");

    //NULL pointer; return failure.
    if (inputFile == NULL || outputFile == NULL){
        printf("ERROR: cannot open input file\n");
        exit(EXIT_FAILURE);
    }

    //If scanned bytes are unequal to the EOF macro, perform the algorithm.
    while((transmittedByteHigh = fgetc(inputFile)) != EOF && (transmittedByteLow = fgetc(inputFile)) != EOF){
        //Decode bytes if function is true
        if (decodeByte(transmittedByteHigh, transmittedByteLow, &decodedByte)){
            //print decoded byte to output file.
            fputc(decodedByte, outputFile);
        } else{
            //in case something goes wrong.
            printf("ERROR: failed to encode Byte");
        }
    }

    //close both files.
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}