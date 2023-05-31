#include <stdio.h>
#include <stdlib.h>
#include <encoder.h>

int main(int argc, char const *argv[])
{
    //Variables
    FILE * inputFile = NULL;
    FILE * outputFile = NULL;

    uint8_t inputByte;
    uint8_t encodedByteHigh;
    uint8_t encodedByteLow;

    printf("\nNumber of arguments: %d\n", argc);
	printf("Executable file: %s\n", argv[0]);
	printf("Name of input file: %s\n", argv[1]);
    printf("Name of output file: %s\n\n", argv[2]);

    //Open both files.
    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "wb");

    //NULL pointer; return failure.
    if (inputFile == NULL || outputFile == NULL){
        printf("ERROR: cannot open input file\n");
        exit(EXIT_FAILURE);
    }

    //If scanned byte is equal to the EOF macro, perform the algorithm.
    while(fscanf(inputFile, "%c", &inputByte) != EOF){
        //Encode byte if function returns true.
        if(encodeByte(&inputByte, &encodedByteHigh, &encodedByteLow)){
            //Print the encoded data to the output file.
            fprintf(outputFile, "%d %d\n", encodedByteHigh, encodedByteLow);
        } else{
            //In case something goes wrong.
            printf("ERROR: input byte, %d, could not be encoded", inputByte);
        }
    }

    //Close both files.
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}