/*
 *	Description: 	
 *		This program is an exercise to practice debugging, pointers as well as the sorting of values. The application
 *		intends to sort 3 values in ascending order using pointers. However the program is not functional 
 *		as it intentionally includes several bugs. When the bugs are solved the program should behave as exemplified below:
 *
 *										value1	value2	value3
 *					Before sorting:  	15		4		7
 *					After sorting:		4		7		15
 *					
 *		Can you fix the program? Hints:
 *			- Think of reading and fixing the warning and/or error messages from the compiler
 * 			- Consider using the debugger to facilitate the process of finding bugs
 * 			- Thoroughly verify the validity of your solution by testing several combination in input values
 * 	
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 24 March 2023
 */

#include <stdio.h>
#include "sort.h"


int main()
{
	int value1 = 4; 
	int value2 = 15; 
	int value3 = 7; 
	
	/*
	 * Swap function
	 */
	printf("\nBefore Swap:\n");
	printf("The first value is: %d\n", value1);
	printf("The second value is: %d\n", value2);
	//swap(&value1, &value2);
	printf("\nAfter Swap:\n");
	printf("The first value is: %d\n", value1);
	printf("The second value is: %d\n", value2);
	
	/*
	 * Sort3 function
	 */
	printf("\nBefore Sort3:\n");
	printf("The first value is: %d\n", value1);
	printf("The second value is: %d\n", value2);
	printf("The third value is: %d\n", value3);
	sort3(&value1, &value2, &value3);
	printf("\nAfter Sort3:\n");
	printf("The first value is: %d\n", value1);
	printf("The second value is: %d\n", value2);
	printf("The third value is: %d\n", value3);

	return (0);
}

