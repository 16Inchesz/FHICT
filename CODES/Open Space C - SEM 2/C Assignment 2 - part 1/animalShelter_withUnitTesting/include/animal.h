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

/// @brief function that shows all animals in the shelter.
/// @param Animal*
/// @param number_of_animals
/// @return true on success and false on failure.
bool show_animals(Animal*, int);

/// @brief function that adds a new animal to the shelter by using a new_animal object.
/// @param Animal*
/// @param number_of_animals*
/// @param new_animal 
/// @return true on success and false on failure.
bool add_animal(Animal*, int*, Animal);

/// @brief This function adds a new animal to the shelter without making use of user inputs
/// @param  Animal*
/// @param  number_of_animals*
/// @param  new_animal
/// @return true of successes and false on failure.
bool add_animal_unit_test(Animal*, int*, Animal);

/// @brief function that allows you to search for an animal within the shelter by its name.
/// @param Animal*
/// @param number_of_animals
/// @return true on success and false on failure.
bool search_animal_by_name(Animal*, int);

/// @brief this function allows the search of an animal within the shelter without user input.
/// @param  animal
/// @param  number_of_animals
/// @param  animal_name
/// @return true on successes and false on failure.
bool search_animal_by_name_unit_test(Animal*, int, char[]);

/// @brief function that allows you to update the species of the specific animal using its chip number.
/// @param Animal*
/// @param number_of_animals
/// @return true on success and false on failure.
bool update_animal_species(Animal*, int);

/// @brief function that allows the update of the species of specific animal's chipnumber without user input.
/// @param  animal  
/// @param  number_of_animals
/// @param  searched_chip_number
/// @param  new_animal_species
/// @return true on successes and false on failure.
bool update_animal_species_unit_test(Animal*, int, int, int);

/// @brief function that allows you to remove an animal from the shelter using their specific chip number.
/// @param Animal*
/// @param number_of_animals*
/// @return true on success and false on failure.
bool remove_animal_by_chip_number(Animal*, int*);

/// @brief function that allows the removal of a specific animal using its chip number without user input.
/// @param  animal
/// @param  number_of_animals
/// @param  chip_number
/// @return true on successes and false on failures.
bool remove_animal_by_chip_number_unit_test(Animal*, int*, int);


/// @brief function that sorts all the animals first by species and then within the species, the names in alphabetical order.
/// @param Animal*
/// @param number_of_animals
/// @return true on success and false on failure.
bool sort_animals(Animal*, int);

#endif