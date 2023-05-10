#ifndef SKATER_H
#define SKATER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_NAME_SIZE 20 
#define MAX_NUMBER_SKATERS 100

typedef struct{
    char first_name[MAX_NAME_SIZE];
    int age;
    int score;
}Skater;

bool update_score_by_name(Skater* skaters, int number_of_skaters, char first_name[], int new_score);
#endif