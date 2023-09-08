#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //variables
    FILE * inputFile = NULL;
    FILE * outputFile = NULL;
    char character;
    char upperChar;

    printf("\nNumber of arguments: %d\n", argc);
	printf("Executable file: %s\n", argv[0]);
	printf("Name of input file: %s\n", argv[1]);
    printf("Name of output file: %s\n\n", argv[2]);

    //open both files
    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");

    //idiot proof
    if (inputFile == NULL || outputFile == NULL){
        printf("ERROR: cannot open input file\n");
        exit(EXIT_FAILURE);
    }


    printf("the content of the file is: \n");
    //reading algorithm
    while ((character = fgetc(inputFile)) != EOF){
        putchar(character); //print input file characters

        upperChar = toupper(character); //make characters upper case.

        fputc(upperChar, outputFile);   //write to ouptut file.
    }
    
    //close both files.
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
