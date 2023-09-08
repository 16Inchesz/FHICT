#ifndef _STUDENT_H
#define _STUDENT_H

#include <stdbool.h>

#define MAX_SIZE_NAME 50
#define MAX_STUDENTS 30

/*
 * Declaration of structure to hold student data
 */
typedef struct
{
    char name[MAX_SIZE_NAME];   // First name (e.g. Anna)
    int id;                     // student id (e.g. 541278)
}student;

/*
 *  Read the list of students from the terminal
 */
bool getStudentData(student*, int);

/*
 *  Write the list of students to the terminal
 */
bool printStudentData(student*, int);

/*
 *  Update the name of a student given by id
 */
bool updateStudentNameById(student*, int, int, char[]);

/*
 *  Update the id of a student given by name
 */
bool updateStudentIdByName(student*, int, int, char[]);

/*
 *  Sort the list of student by alphabetical order
 */
bool sortStudentByName(student*, int);

#endif

