#ifndef CALCULATION_H
#define CALCULATION_H

#define STUDENT_NAME 50
#define NR_OF_GRADES 4
#define NR_OF_STUDENTS 3
#define PASSINGGRADE 5.5

/*
 * Declaration of a structure to hold student data
 */ 
typedef struct student{
    char name[STUDENT_NAME];
    int pcn;
    int age;
    float grades[NR_OF_GRADES];	
}student;


/// @brief Function to calculate the average grade
/// @param  grades 
/// @return averagegrade
float calculateAverageGrade(float[]);

/// @brief Function to find Highest Grade of student
/// @param grades 
/// @param size
/// @return highestgrade
float FindHighestGrade(float[], int);

/// @brief Function to find the pcn of the youngest student.
/// @param studentarray 
/// @param numberofstudent
/// @return pcnyoungeststudent
int FindPCNOfYoungestStudent(student[], int);

/// @brief Function to find how many students have passed
/// @param studentarray 
/// @param numberofstudent
/// @return passingstudents
int FindNROfPassingStudents(student[], int);

#endif