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

/// @brief Function that prints the details of all animals hosted in the shelter
/// @param animals pointer
/// @param number_of_animals 
/// @return bool
bool show_animals(Animal*, int);

/// @brief Function that adds a new animal to the list of hosted animals 
/// @param animals
/// @param number_of_animals
/// @param new_animal
/// @return bool
bool add_animal(Animal*, int*, Animal);

bool search_animal_by_name(Animal*, int);
#endif