#ifndef ANIMAL_H
#define ANIMAL_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH_NAME 30
#define MAX_NUMBER_ANIMAL 20

typedef enum
{
    CAT,
    CHINCHILLA,
    DOG,
    TURTLE,
} Species;

typedef struct
{
    char name[MAX_LENGTH_NAME];
    Species species;
    int chip_number;
} Animal;

// To do : declare your functions

bool show_animals(Animal*, int);

bool add_animal(Animal*, int*, Animal);

bool search_animal_by_name(Animal*, int);

bool update_animal_species(Animal*, int);
#endif