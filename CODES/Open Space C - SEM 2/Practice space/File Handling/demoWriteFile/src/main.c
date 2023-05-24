/*
 *	Description:	This C program demonstrates the basic use of the C standard library
 *					to write characters to a text file. A text file with 10 random characters
 *					is generated
 *					
 *					Type the following command to run the program: ./output/main.exe output.txt
 * 
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 12 May 2023
 */

#include <stdio.h>
#include <stdlib.h> 

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
		
	FILE* outputFile = NULL;	

	/*
	 * Open file output file in writing mode ("w"):
	 *		- File argv[1] is created if the file does exist
	 *		- creates a FILE structure to host the content of file argv[1] in memory
	 *		- returns pointer inputFile pointing the a FILE structure	 
	 */	
	outputFile = fopen(argv[1], "w");
	
	/*
	 * Exit program if opening of the file failed: 
	 */
	if (outputFile==NULL) {
		printf("Error: cannot open output file");
		return 0;
	}

	for (int i=0; i<10; i++) {
		/*
		 * Generate a random character from 'a' to 'z' using standard latin alphabet (26 letters)
		 * To use rand() it is needed to include stdlib.h
		 */
		char randomChar = 'a' + rand() % 26; 

		/*
		 * Write character to the output file using function fputc
		 */
		fputc(randomChar, outputFile);
	}

	/*
	 * Close file argv[1]: 	
	 *		- clears the memory used to host the content of file argv[1] in memory
	 */	
	fclose(outputFile);

	return (0);
}