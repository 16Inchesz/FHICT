#ifndef _STUDENT_H
#define _STUDENT_H

#include <stdbool.h>

#define MAX_SIZE_NAME 50
#define MAX_STUDENTS 30

/*
 * Declaration of structure to hold student data
 */
struct student
{
    char name[MAX_SIZE_NAME];   // First name (e.g. Anna)
    int id;                     // student id (e.g. 541278)
};

/*
 *  Read the list of students from the terminal
 */
bool getStudentData(struct student*, int);

/*
 *  Write the list of students to the terminal
 */
bool printStudentData(struct student*, int);

/*
 *  Update the name of a student given by id
 */
bool updateStudentNameById(struct student*, int, int, char[]);

/*
 *  Update the id of a student given by name
 */
bool updateStudentIdByName(struct student*, int, int, char[]);

/*
 *  Sort the list of student by alphabetical order
 */
bool sortStudentByName(struct student*, int);

#endif

