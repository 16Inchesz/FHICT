#include <stdio.h>
#include "student.h"

/*
 *  Read the list of students from the terminal
 */
bool getStudentData(student *students, int size)
{
	for (int i = 0; i < size; i++){
		scanf("%s", students->name);
		students++;
	}
	return true;
}

/*
 *  Write the list of students to the terminal
 */
bool printStudentData(student *students, int size)
{
	for (int i = 0; i < size; i++){
		printf("%s\n", students->name);
		students++;
	}
	
	return true;
}

// /*
//  *  Update the name of a student given by id
//  */
// bool updateStudentNameById(student *students, int size, int id, char newName[])
// {
//     return true;
// }

// /*
//  *  Update the id of a student given by name
//  */
// bool updateStudentIdByName(student *students, int size, int newId, char name[])
// {
// 	return true;
// }

// /*
//  *  Sort the list of student by alphabetical order
//  */
// bool sortStudentByName(student *students, int size)
// {
// 	return true;
// }