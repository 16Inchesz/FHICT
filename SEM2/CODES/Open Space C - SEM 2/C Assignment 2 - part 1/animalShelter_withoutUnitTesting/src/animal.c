#include "animal.h"


//-----------------------------------------------------------------------------------------------------------------------------
bool show_animals(Animal *animals, int number_of_animals){
    //idiot proof
    if ((animals == NULL) || (number_of_animals < 0)){
        return false;
    }
    
    //no animals in shelter 
    if (number_of_animals == 0){
        printf("there are no animals in the shelter.\n");
        return true;
    }

    //animals in the shelter
    printf("Here is a list of animals in the shelter:\n");
    for (int i = 0; i < number_of_animals; i++){
        printf("Name: %s, Species: %d, Chip number: %d\n", animals->name, animals->species, animals->chip_number);
        animals++;
    }
    return true;

}

//-----------------------------------------------------------------------------------------------------------------------------
bool add_animal(Animal *animals, int *number_of_animals, Animal new_animal){
    //idiot proof
    if ((animals == NULL) || (number_of_animals == NULL)){
        return false;
    }
    if (*number_of_animals > MAX_NUMBER_ANIMAL){
        return false;
    }
    
    // adding an animal to new_animal
    int add_animal_species;
    printf("Enter the name of the animal: ");
    scanf("%s", new_animal.name);   //char array; already a pointer.
    printf("Enter the species of the animal (0 = cat, 1 = chinchilla, 2 = dog, 3 = turtle): ");
    scanf("%d", &add_animal_species);   //??
    new_animal.species = add_animal_species;
    printf("Enter the chip number of the animal: ");
    scanf("%d", &new_animal.chip_number);

    //shelter at max capacity.
    if (*number_of_animals == MAX_NUMBER_ANIMAL){
        printf("the shelter has reached maximum capacity.\n");
        return true;
    }

    //if an animal with chip num already exists.
    for (int i = 0; i < *number_of_animals; i++){
        if (animals->chip_number == new_animal.chip_number){
            printf("an animal with this ID already exists.\n");
            return true;
        }
    }

    //adding new animal to animal.
    animals[*number_of_animals] = new_animal;
    (*number_of_animals)++;
    printf("animal was added succesfully.\n");
    return true;
}

//-----------------------------------------------------------------------------------------------------------------------------
bool search_animal_by_name(Animal *animals, int number_of_animals){
    //idiot proof
    if ((animals == NULL) || (number_of_animals < 0)){
        return false;
    }

    char searched_name[MAX_LENGTH_NAME];
    int name_count = 0;

    printf("enter the name of the animal you are searching for: ");
    scanf("%s", searched_name);

    //if animals with the same name were found.
    for (int i = 0; i < number_of_animals; i++){
        if (strcmp((animals)->name, searched_name) == 0){
            name_count++;
        }
        animals++;
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

//-----------------------------------------------------------------------------------------------------------------------------
bool update_animal_species(Animal *animals, int number_of_animals){
    //idiot proofing
    if ((animals == NULL) || (number_of_animals < 0)){
        return false;
    }
    
    int searched_chip_number;
    int new_animal_species;

    printf("Enter the chip number of the animal you want to update: ");
    scanf("%d", &searched_chip_number);

    //checks if searched num == to existing chip num. if true, switches the species.
    for (int i = 0; i < number_of_animals; i++) {
        if (animals->chip_number == searched_chip_number) { 
            printf("Enter the new species of the animal (0 = cat, 1 = chinchilla, 2 = dog, 3 = turtle): ");
            //test case here for species if its < 0 or > 0
            scanf("%d", &new_animal_species);
            animals->species = new_animal_species;
            printf("Species updated successfully.\n");
        }
        animals++;
    }
    return true;
}

//-----------------------------------------------------------------------------------------------------------------------------
bool remove_animal_by_chip_number(Animal *animals, int *number_of_animals){
    //idiot proofing
    if ((animals == NULL) || (number_of_animals == NULL)){
        return false;
    }

    if (*number_of_animals == 0){
        printf("there are no animals in the shelter.\n");
        return true;
    }

    //if animal with same chip number found and removed.
    int chip_number = -1;
    printf("Enter the chip number of the animal you wish to remove: ");
    scanf("%d", &chip_number);
    int animal_to_remove = -1;
    for (int i = 0; i < *number_of_animals; i++) {
        if (animals->chip_number == chip_number) {
            animal_to_remove = i;
        }
        animals++;
    }

    //if animals was not found in shelter (same value as start).
    if (animal_to_remove == -1) {
        printf("No animal with chip number %d was found in the shelter.\n", chip_number);
        return true;
    }
    
    //shift them to the left.
    for (int i = animal_to_remove; i < *number_of_animals - 1; i++) {
        animals[i] = animals[i + 1];
    }

    (*number_of_animals)--; //remove an animal
    printf("Animal with chip number %d removed successfully from the shelter.\n", chip_number);
    return true; 
}

//-----------------------------------------------------------------------------------------------------------------------------
bool sort_animals(Animal *animals, int number_of_animals){
    //idiot proofing.
    if ((animals == NULL) || (number_of_animals < 0)){
        return false;
    }

    //no animals to sort.
    if (number_of_animals <= 1) {
        printf("There are no animals to sort.\n");
        return true;
    }
    
    //can be optimized by adding in 1 for loop.
    //bubble sort species
    for (int i = 0; i < number_of_animals - 1; i++) {
        for (int j = 0; j < number_of_animals - i - 1; j++) {
            if (animals[j].species > animals[j+1].species) {    //check if species at both indexes are the same.
                Animal temp = animals[j];
                animals[j] = animals[j+1];
                animals[j+1] = temp;
            }
        }
    }
    
    //bubble sort names in alphabetical order within species
    for (int i = 0; i < number_of_animals - 1; i++) {
        for (int j = 0; j < number_of_animals - i - 1; j++) {
            if (animals[j].species == animals[j+1].species &&
                strcmp(animals[j].name, animals[j+1].name) > 0) {   //checks if species at both indexes are the same && compares the names using strcmp. 
                Animal temp = animals[j];                           //strcmp compares ascii values. if > ), first value comes first.
                animals[j] = animals[j+1];
                animals[j+1] = temp;
            }
        }
    }
    printf("animals sorted succesfully.\n");
    return true;
}



