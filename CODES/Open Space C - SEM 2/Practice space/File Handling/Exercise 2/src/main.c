#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE* outputfile = NULL;

    printf("\nNumber of arguments: %d\n", argc);
	printf("Executable file: %s\n", argv[0]);
	printf("Name of input file: %s\n", argv[1]);

    //open file
    outputfile = fopen(argv[1], "w");

    //random character algorithm
    for (int i = 0; i < 15; i++){

        char randomChar = 'a' + rand() % 26;    //random character.

        fputc(randomChar, outputfile);  //assign random character to file.
    }

    //close file
    fclose(outputfile);
    
    return 0;
}
