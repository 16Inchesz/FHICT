#include "animal.h"

// To do : define your functions

bool show_animals(Animal *animals, int number_of_animals){
    //idiot proof
    if ((animals == NULL) || (number_of_animals < 0)){
        return false;
    }
    
    //no animals in shelter 
    if (number_of_animals == 0){
        printf("there are no animals in the shelter.\n");
        return true;    //valid response??
    }

    //animals in the shelter
    printf("Here is a list of animals in the shelter:\n");
    for (int i = 0; i < number_of_animals; i++){
        printf("Name: %s, Species: %d, Chip number: %d\n", animals->name, animals->species, animals->chip_number);
        animals++;
    }
    return true;

}

bool add_animal(Animal *animals, int *number_of_animals, Animal new_animal){
    //idiot proof
    if ((animals == NULL) || (number_of_animals == NULL)){
        return false;
    }

    printf("Enter the name of the animal: ");
    scanf("%s", new_animal.name);   //char array; already a pointer.
    printf("Enter the species of the animal (0 = cat, 1 = chinchilla, 2 = dog, 3 = turtle): ");
    scanf("%d", &new_animal.species);   //??
    printf("Enter the chip number of the animal: ");
    scanf("%d", &new_animal.chip_number);

    //shelter at max capacity.
    if (*number_of_animals == MAX_NUMBER_ANIMAL){
        printf("the shelter has reached maximum capacity.\n");
        return true;
    }

    for (int i = 0; i < *number_of_animals; i++){
        if (animals->chip_number == new_animal.chip_number){
            printf("an animal with this ID already exists.\n");
            return true;
        }
    }

    animals[*number_of_animals] = new_animal;
    (*number_of_animals)++;
    printf("animal was added succesfully.\n");
    return true;
}

bool search_animal_by_name(Animal *animals, int number_of_animals){
    //idiot proof
    if ((animals == NULL) || (number_of_animals < 0)){
        return false;
    }

    char searched_name[MAX_LENGTH_NAME];
    int name_count = 0;

    printf("enter the name of the animal you are searching for: ");
    scanf("%s", searched_name);

    for (int i = 0; i < number_of_animals; i++){
        if (strcmp(animals->name, searched_name) == 0){
            name_count++;
        }
    }

    //no animals with this name in shelter
    if (name_count == 0){
        printf("there are no animals in the shelter with this name: '%s' \n", searched_name);
        return true;
    }

    //total animals with this name in shelter
    printf("the number of animals with this name: '%s' are '%d'.\n", searched_name, name_count);
    return true;
}







