#include <stdio.h>
#include "channel.h"

int main(int argc, char const *argv[])
{
    //variables
    FILE * inputFile = NULL;
    FILE * outputFile = NULL;

    //Variables for channel.
    int encodedByte;
    uint8_t transmittedByte;

    //array for tracking how many times bit has been flipped
    int FlippedBits[NUMBER_OF_BITS] = {0};

    printf("\nNumber of arguments: %d\n", argc);
	printf("Executable file: %s\n", argv[0]);
	printf("Name of input file: %s\n", argv[1]);
    printf("Name of output file: %s\n\n", argv[2]);

    //open files.
    inputFile = fopen(argv[1], "rb");
    outputFile = fopen(argv[2], "wb");

    //NULL pointer; return failure.
    if (inputFile == NULL || outputFile == NULL){
        printf("ERROR: cannot open input file\n");
        exit(EXIT_FAILURE);
    }

    //init the seed for the random function.
    srand(time(NULL));

    //Bit Flipping algorithm
    //Must use casting. uint8_t does not process value of -1
    while((encodedByte = fgetc(inputFile)) != EOF){
        //apply interference to encodedByte if function is true.
        if(TransmitByte((uint8_t)encodedByte, &transmittedByte, FlippedBits)){
            //print transmitted to output file.
            fputc(transmittedByte, outputFile);
        } else {
            //in case something goes wrong.
            printf("ERROR: failed to transmit Byte");
        }
    }

    //Frequency of bit flip
    for(int i = 0; i < NUMBER_OF_BITS; i++){
        printf("Bit %d has been flipped %d times.\n", i, FlippedBits[i]);
    }

    //close both files.
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}