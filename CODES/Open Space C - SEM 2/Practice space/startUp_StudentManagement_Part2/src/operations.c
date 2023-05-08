#include "operations.h"

float calculateAverageGrade(float grades[]){
    float averageGrade = 0;

	for (int i=0; i<4; i++) {
		averageGrade += grades[i];
	}

	averageGrade /= 4;

	return averageGrade;
}

float FindHighestGrade(float grades[]){
	float highest = 0;
	
	for (int i = 0; i < 4; i++){
		if (grades[i] > highest){
			highest = grades[i];
		}
	}
	return highest;
}

int FindYoungestStudent(student studentArray[]){
	int youngest = 100;

	for (int i = 0; i < 3; i++){
		if (studentArray->age < youngest){
			youngest = studentArray->age;
		}
		studentArray++;
	}	
	return youngest;
}

int PcnOfYoungest(student studentArray[], int youngest){
	int pcn = 0;

	for (int i = 0; i < 3; i++){
		if (studentArray->age == youngest){
			pcn = studentArray->pcn;
		}
		studentArray++;
	}	
	return pcn;
}