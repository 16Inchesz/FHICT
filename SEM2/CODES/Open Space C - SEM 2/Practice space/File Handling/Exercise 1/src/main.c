#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char character;
    int words = 1;
    int numOfLines = 1;

    FILE* inputFile = NULL;

    //open file.
    inputFile = fopen("input.txt", "r");

    //idiot proofing
    if (inputFile == NULL){
        printf("ERROR: file cannot be opened\n");
        exit(EXIT_FAILURE);
    }

    //read number of characters
    while ((character = fgetc(inputFile)) != EOF){
        if (character == ' '){  //check if there is a space.
            words++;
        }
        printf("%c", character);

        if (character == '\n'){ //check if there is a new line.
            numOfLines++;
        }
    }
    printf("\nthe number of words are: %d\n", words);
    printf("the number of lines are: %d\n", numOfLines);

    //close file
    fclose(inputFile);
    return 0;
}
