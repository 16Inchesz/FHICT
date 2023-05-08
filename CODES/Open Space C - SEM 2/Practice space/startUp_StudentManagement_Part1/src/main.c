/*
 *	Description:	Exercises to practice functions and structures:
 *						- Exercise 1 : 	Refactor the following code using function(s) {done}
 *						- Exercise 2 : 	Refactor your code from exercise 1 using structure(s) in addition to function(s) {done}
 *		
 *						- Note:	You are not expected to read inputs from the terminal (i.e. no scanf needed)
 * 								Remember to	both declare and define your function(s)
 * 
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 10 February 2023
 */

#include <stdio.h>
#include <string.h>

float CalculateAverageGrade(float studentgrades[]){
	float sum = 0;
	for (int i = 0; i < 5; i++){
		sum += studentgrades[i];
	}
	float averageGrade = sum / 5;
	return averageGrade;
}

int main()
{
	typedef struct
	{
		char studentName[50];
		float studentGrades[5];
	}Students;

	Students student1 = {"Lisa", {9.0, 6.5, 8.5, 7.0, 8.0}};
	Students student2 = {"Eric", {6.0, 6.0, 8.0, 7.5, 7.0}};

	float averageGradeStudent1;
	float averageGradeStudent2;

	// Calculate average grade student1
	averageGradeStudent1 = CalculateAverageGrade(student1.studentGrades);

	// print average grade of student 1
	printf("The average grade of %s is: %.1f \n", student1.studentName, averageGradeStudent1);

	// Calculate average grade student2
	averageGradeStudent2 = CalculateAverageGrade(student2.studentGrades);	

	// print average grade of student 2
	printf("The average grade of %s is: %.1f \n", student2.studentName, averageGradeStudent2);

	return (0);
}