/*
 *	Description:	Exercises to practice functions, structures and modules:
 *
 * 					1. Add code to initialize studentArray (at first you are not expected to read inputs from the terminal)
 * 					2. Refactor the code below (in functions main and in calculateAverageGrade) by using macros
 * 					3. Refactor the code below by using a module
 * 					4. Add a function to find the highest grade of a student
 * 					5. Add a function to find the pcn number of the youngest student
 * 					6. Add a function to find the number of passing student. A student pass if all graded are at 5.5
 * 					7. Test all your functions by printing results to the terminal		
 *                 	8. In case you are done with the 7 exercises above, try to initialize studentArray by reading the inputs from the terminal ( not expected to read inputs from the terminal (e.g. using scanf)
 * 
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 24 Feb 2023
 */

#include <stdio.h>

/*
 * Declaration of a structure to hold student data
 */
struct student{
    char name[50];
    int pcn;
    int age;
    float grades[4];	// lowest grade is 0, highest grade is 10, passing grade is 5.5
};

/*
 * Declarations of a function to calculate the average grade of a student
 */
float calculateAverageGrade(float[]);


int main()
{
	struct student studentArray[3]; 
	
	// Calculate average grade of first student
	float averageGrade = calculateAverageGrade(studentArray[0].grades);
	
	// Print average grade of first student
	printf("The average grade of %s is: %f \n", studentArray[0].name, averageGrade);

	return (0);
}

/*
 * Definition of a function to calculate the average grade of a student
 */
float calculateAverageGrade(float grades[])
{
    float averageGrade = 0;

	for (int i=0; i<4; i++) {
		averageGrade += grades[i];
	}

	averageGrade /= 4;

	return averageGrade;
}


