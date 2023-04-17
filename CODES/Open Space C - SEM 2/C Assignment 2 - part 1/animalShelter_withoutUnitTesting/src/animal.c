#include "animal.h"

// To do : define your functions

bool show_animals(Animal *animals, int number_of_animals){
    //idiot proof
    if (animals == NULL || number_of_animals < 0){
        return false;
    }
    
    //no animals in shelter 
    if (number_of_animals == 0){
        printf("there are no animals in the shelter.\n");
        return true;    //valid response
    }

    //animals in the shelter
    printf("Here is a list of animals in the shelter:\n");
    for (int i = 0; i < number_of_animals; i++){
        printf("Name: %s, Species: %d, Chip number: %d\n", animals->name, animals->species, animals->chip_number);
    }
    return true;

}



