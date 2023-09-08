/*
 *	Description:	
 *      	This program is the starting code of a C program to manage the personal data of students enrolled in a educational institution. 
 * 			Perform the following exercises to practice the manipulation of (arrays of) structures with pointers. 
 *
 * 			1. A student structure is declared in a header file (student.h). The structure is used to represent the personal data of a student. 
 * 			Can you refactor the code to take advantage of the typedef keyword? {done}
 *
 * 			2. The program can handle the details of maximally 30 students as defined by macro MAX_STUDENTS. 
 * 			Can you read the details of e.g. 3 students from the terminal by implementing the function getStudentData? 
 * 			Note that the actual number of students to be processed (e.g. 3) can be read from the terminal in variable size
 *
 * 			3. Write the details of students to the terminal by implementing the function printStudentData
 *
 * 			4. Update the name of a student given by id by implementing the function updateStudentNameById. 
 * 			Can you read the name and id of students from the terminal?
 * 
 * 			5. Update the id of a student given by name by implementing the function updateStudentIdByName. 
 * 			In the context of this exercise we assume that all students have a different name.
 * 			Remember to read the name and id of students from the terminal
 *
 * 			6. Will you take the challenge of sorting the list of students by name (e.g. in alphabetical order)?
 * 			
 * 			7. Have you thought of checking the validity of pointer(s0 in functions?
 * 
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 31 March 2023
 */

#include <stdio.h>
#include "student.h"


int main ()
{
	student students[MAX_STUDENTS];
		
	/*
	 * Exercises : manipulating array of structures in functions using pointers
	 */
	int size = 0;	// Number of students to be entered
	printf("Please input the number of students:\n");
    scanf("%d", &size);
	

	/*
	 * getStudentData
	 */
	printf("\n\nGet student data\n");
	printf("--------------------\n");
	printf("please enter the names of the students below.\n");
    getStudentData(students, size);

	/*
	 * printStudentData
	 */
	printf("\n\nPrint student data\n");
	printf("----------------------\n");
	printStudentData(students, size);

	// /*
	//  * updateStudentNameById
	//  */
	// printf("\n\nUpdate student name by Id\n");
	// printf("-----------------------------\n");
	// int id=0;
	// char newName[MAX_SIZE_NAME];
	// printf("Enter student id:\n");
	// // Use here scanf to read the id of a student from the terminal
	// printf("Enter new student name:\n");
	// // Use here scanf to read the name of a student from the terminal
	// updateStudentNameById(students, size, id, newName);

	// /*
	//  * updateStudentIdByName
	//  */
	// printf("\n\nUpdate student Id by name\n");
	// printf("-----------------------------\n");
	// int newId=0;
	// char name[MAX_SIZE_NAME];
	// printf("Enter student name:\n");
	// // Use here scanf to read the name of a student from the terminal
	// printf("Enter new student id:\n");
	// // Use here scanf to read the id of a student from the terminal
	// updateStudentIdByName(students, size, newId, name);


	// /*
	//  * printStudentData
	//  */
	// printf("\n\nPrint student data\n");
	// printf("----------------------\n");
	// printStudentData(students, size);


	// /*
	//  * sortStudentByName
	//  */
	// printf("\n\nSort student by name\n");
	// printf("------------------------\n");
	// sortStudentByName(students, size);
}