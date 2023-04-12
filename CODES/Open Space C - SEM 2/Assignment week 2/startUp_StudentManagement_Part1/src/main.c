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

struct student{
	char name[50];
	int pcn;
	int age;
	float grades[5];
};

float calculateAverage(float grades[]){
	float sum = 0, averageGrade = 0;
	for (int i = 0; i < 5; i++) {
		sum += grades[i];
	}
	averageGrade = sum / 5;
	return averageGrade;
}

void printAverageGrade(float averageGrade){
	printf("the average grade is: %.1f \n", averageGrade);
}

int main()
{
	//declaring and initializing both students.
	struct student student0 = {"Lisa", 875922, 18, {9.0, 6.5, 8.5, 7.0, 8.0}};
	struct student student1 = {"Eric", 458216, 18, {6.0, 6.0, 8.0, 7.5, 7.0}};

	//printing the average grade of both students.
	printAverageGrade(calculateAverage(student0.grades));
	printAverageGrade(calculateAverage(student1.grades));

	return (0);
}

/*
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
*/