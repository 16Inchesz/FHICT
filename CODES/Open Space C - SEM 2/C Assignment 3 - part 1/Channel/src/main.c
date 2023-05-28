#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //variables
    FILE * inputFile = NULL;
    FILE * outputFile = NULL;

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

    //close both files.
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}