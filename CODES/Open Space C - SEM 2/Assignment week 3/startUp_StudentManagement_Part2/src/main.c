/*
 *	Description:	Exercises to practice functions, structures and modules:
 *
 * 					1. Add code to initialize studentArray (at first you are not expected to read inputs from the terminal)
 * 					2. Refactor the code below (in functions main and in calculateAverageGrade) by using macros (done)
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
#include "calculaton.h"

int main()
{
	struct student studentArray[NR_OF_STUDENTS] = {	{"Johnson", 1234, 21, {5.5, 5.6, 6.7, 8.9}},
													{"Nathalie", 2345, 21, {6.5, 5.7, 7.7, 6.6}},
													{"Veronique", 3456, 20, {5.8, 5.9, 9.2, 7.9}}};

	float averageGrade = calculateAverageGrade(studentArray[0].grades);
	float highestGrade = FindHighestGrade(studentArray[0].grades, NR_OF_GRADES);
	int youngestStudentPcn = FindPCNOfYoungestStudent(studentArray, NR_OF_STUDENTS);
	int studentsPassed = FindNROfPassingStudents(studentArray, NR_OF_STUDENTS);
	
	//Print average grade of a student.
	printf("The average grade of %s is: %.1f \n", studentArray[0].name, averageGrade);

	//print highest grade of a student.
	printf("the highest grade of %s is: %.1f \n", studentArray[0].name, highestGrade);

	//print the PCN of youngest student.
	printf("The PCN of the youngest student is: %d \n", youngestStudentPcn);

	//print the amount of students passed.
	printf("The amount of students passed is: %d \n", studentsPassed);

	return (0);
}

