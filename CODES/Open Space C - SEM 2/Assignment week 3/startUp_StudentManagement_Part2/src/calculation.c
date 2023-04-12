#include <stdio.h>
#include "calculaton.h"

float calculateAverageGrade(float grades[]){
	float averageGrade = 0;
	for (int i = 0; i < NR_OF_GRADES; i++){
		averageGrade += grades[i];
	}
	averageGrade /= NR_OF_GRADES;
	return averageGrade;
}

float FindHighestGrade(float grades[], int size){
    float highestGrade = grades[0];
    for (int i = 0; i < size; i++){
        if (highestGrade < grades[i]){
            highestGrade = grades[i];
        }
    }
    return highestGrade;
}

int FindPCNOfYoungestStudent(student students[], int numberOfStudents ){
    int youngest = students[0].age;
    int pcn = students[0].pcn;
    for (int i = 0; i < numberOfStudents; i++){
        if (youngest > students[i].age){
            pcn = students[i].pcn;
            youngest = students[i].age;
        }
    }
    return pcn;
}

int FindNROfPassingStudents(student students[], int numberOfStudents){
    int studentsPassed = 0;
    for (int i = 0; i < numberOfStudents; i++){
        for (int j = 0; j < NR_OF_GRADES; j++){
            if(students[i].grades[j] > PASSINGGRADE){
                studentsPassed++;
            }
        }
    }
    return studentsPassed;
}
