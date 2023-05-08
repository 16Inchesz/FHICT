/*
 *	Description:	Exercises to practice functions and structures:
 *						- Exercise 1 : 	Refactor the following code using function(s)
 *						- Exercise 2 : 	Refactor your code from exercise 1 using structure(s) in addition to function(s)
 *		
 *						- Note:	You are not expected to read inputs from the terminal (i.e. no scanf needed)
 * 								Remember to	both declare and define your function(s)
 * 
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 10 February 2023
 */

#include <stdio.h>
#include <string.h>

int main()
{
	// Declare and initialize student1
	char studentName1[50] = "Lisa";
	int numberStudent1 = 875922;
	int ageStudent1 = 18;
	float gradesStudent1[5] = {9.0, 6.5, 8.5, 7.0, 8.0};
	float averageGradeStudent1;

	// Declare and initialize student2
	char studentName2[50] = "Eric";
	int numberStudent2 = 458216;
	int ageStudent2 = 20;
	float gradesStudent2[5] = {6.0, 6.0, 8.0, 7.5, 7.0};
	float averageGradeStudent2;

	// Calculate average grade student1
	float sum = 0;
	for( int i=0; i<5; i++) {
		sum += gradesStudent1[i];
	}
	averageGradeStudent1 = sum / 5;
	
	// print average grade of student 1
	printf("The average grade of %s is: %.1f \n", studentName1, averageGradeStudent1);

	// Calculate average grade student2
	sum = 0;
	for( int i=0; i<5; i++) {
		sum += gradesStudent2[i];
	}
	averageGradeStudent2 = sum / 5;
		
	// print average grade of student 2
	printf("The average grade of %s is: %.1f \n", studentName2, averageGradeStudent2);

	return (0);
}