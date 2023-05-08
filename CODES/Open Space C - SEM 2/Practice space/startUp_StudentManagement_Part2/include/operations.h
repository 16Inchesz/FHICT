#ifndef OPERATIONS_H
#define OPERATIONS_H

typedef struct{
    char name[50];
    int pcn;
    int age;
    float grades[4];
}student;

//calculate average grade
float calculateAverageGrade(float[]);

//find the highest grade of a student
float FindHighestGrade(float[]);

//find the pcn of youngest student
int FindYoungestStudent(student[]);

int PcnOfYoungest(student[], int);

#endif