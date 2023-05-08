/*
 *	Description:	Exercises to practice functions, structures and modules:
 *
 * 					1. Add code to initialize studentArray (at first you are not expected to read inputs from the terminal)	{done}
 * 					2. Refactor the code below (in functions main and in calculateAverageGrade) by using macros	{done}
 * 					3. Refactor the code below by using a module {done}
 * 					4. Add a function to find the highest grade of a student {done}
 * 					5. Add a function to find the pcn number of the youngest student {done}
 * 					6. Add a function to find the number of passing student. A student pass if all graded are at 5.5
 * 					7. Test all your functions by printing results to the terminal {done}	
 *                 	8. In case you are done with the 7 exercises above, try to initialize studentArray by reading the inputs from the terminal ( not expected to read inputs from the terminal (e.g. using scanf)
 * 
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 24 Feb 2023
 */

#include <stdio.h>
#include "operations.h"


int main(){
	student studentArray[NUMBER_OF_STUDENTS] = {	{"Lisa", 123, 1, {5.5, 4.7, 8.4, 9.2}},
													{"Eric", 234, 18, {6.3, 9.7, 7.2, 6.8}},
													{"Emilia", 345, 17, {8.3, 6.7, 5.7, 5.5}}
												}; 
	
	// Calculate and print average grade of first student
	float averageGrade = calculateAverageGrade(studentArray[1].grades);
	printf("The average grade of %s is: %.2f \n", studentArray[1].name, averageGrade);

	//Calculate and print highest grade of a student
	float highestGrade = FindHighestGrade(studentArray[1].grades);
	printf("the highest grade of %s is: %.2f \n", studentArray[1].name, highestGrade);

	//find  and print pcn of the youngest student
	int youngest = FindYoungestStudent(studentArray);
	int pcn = PcnOfYoungest(studentArray, youngest);
	printf("the pcn of the youngest student is: %d \n", pcn);

	return (0);
}




