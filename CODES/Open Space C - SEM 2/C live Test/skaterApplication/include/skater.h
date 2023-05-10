#ifndef SKATER_H
#define SKATER_H

#define MAX_NAME_SIZE 20 
#define MAX_SKATERS_SIZE 100

typedef struct{
    char first_name[MAX_NAME_SIZE];
    int age;
    int score;
}Skater;

#endif