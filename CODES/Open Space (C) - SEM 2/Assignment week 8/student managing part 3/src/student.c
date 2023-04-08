#include <stdio.h>
#include "student.h"

/*
 *  Read the list of students from the terminal
 */
bool getStudentData(struct student* students, int size)
{
	if (students == NULL){
		return false;
	}
	if ((size < 0) || size > MAX_STUDENTS){
		return false;
	}
	for (int i = 0; i < size; i++){
		printf("Get Name:");
		scanf("%s", students->name);
		printf("Get ID:");
		scanf("%d", &students->id);
		students++;
	}
	return true;
}

/*
 *  Write the list of students to the terminal
 */
bool printStudentData(struct student* students, int size)
{
	if (students == NULL){
		return false;
	}
	if ((size < 0) || size > MAX_STUDENTS){
		return false;
	}

	for (int i = 0; i < size; i++){
		printf("name: %s\n", students->name);
		printf("Id: %d\n", students->id);
		students++;
	}
	return true;
}

/*
 *  Update the name of a student given by id
 */
bool updateStudentNameById(struct student* students, int size, int id, char newName[])
{
    return true;
}

/*
 *  Update the id of a student given by name
 */
bool updateStudentIdByName(struct student* students, int size, int newId, char name[])
{
	return true;
}

/*
 *  Sort the list of student by alphabetical order
 */
bool sortStudentByName(struct student *students, int size)
{
	return true;
}