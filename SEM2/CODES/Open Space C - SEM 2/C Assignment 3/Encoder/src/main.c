#include <stdlib.h>
#include <encoder.h>

//./output.main.exe
int main(int argc, char const *argv[])
{
    //File pointers ariables
    FILE * inputFile = NULL;
    FILE * outputFile = NULL;

    //Variables for encoding.
    char character;
    uint8_t encodedByteHigh = 0;
    uint8_t encodedByteLow = 0;

    //printing name of input and output file.
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

    //If scanned byte is unequal to the EOF macro, perform the algorithm.
    while((character = fgetc(inputFile)) != EOF){
        //Encode byte if function returns true. (c is already a unint8_t)
        if(encodeByte(character, &encodedByteHigh, &encodedByteLow)){
            //Print the encoded data to the output file.
            fputc(encodedByteHigh, outputFile);
            fputc(encodedByteLow, outputFile);
        } else{
            //In case something goes wrong.
            printf("ERROR: input byte, %d, could not be encoded", character);
        }
    }

    //Close both files.
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}