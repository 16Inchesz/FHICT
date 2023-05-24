/*
 *	Description:	This C program demonstrates the basic use of the C standard library
 *					to read characters from a text file. The content of the text file
 *					is printed to the terminal
 *					
 *					Type the following command to run the program: ./output/main.exe input.txt
 * 
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 12 May 2023
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	/*
	 * argc and argv are used to pass command-line arguments to the main function
	 * argc stands for argument count
	 * argv stands for argument vector
	 */
	printf("\nNumber of arguments: %d\n", argc);
	printf("Executable file: %s\n", argv[0]);
	printf("Name of input file: %s\n", argv[1]);
	printf("\n");

	FILE* inputFile = NULL;	
	
	/*
	 * Open file argv[1] in reading mode ("r"):
	 *		- file argv[1] must exist when opening in reading mode
	 *		- creates a FILE structure to host the content of file argv[1] in memory
	 *		- returns pointer inputFile pointing the a FILE structure	 
	 */
	inputFile = fopen(argv[1], "r");	 // 26
	
	/*
	 * Exit program if opening of the file failed
	 */
	if (inputFile==NULL) {
		printf("Error: cannot open input file");
		exit(EXIT_FAILURE);
		return 0;
	}

	/*
	 * Read the file character by character until the end of the file is reached (EOF)
	 * Function fgetc returns EOF when end of file is reached
	 */
	printf("\nThe content of the file is :\n");
	char inputChar;
	while( (inputChar = fgetc(inputFile)) != EOF) {
		printf("%c", inputChar);
	}
	
	/*
	 * Close file argv[1]: 	
	 *		- clears the memory used to host the content of file argv[1] in memory
	 */		
	fclose(inputFile);

	return (0);
}