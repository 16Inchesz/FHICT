#include <stdio.h>
#include "animal.h"

int main()
{
    Animal animals[MAX_NUMBER_ANIMAL];
    int number_of_animals = 0;
    int option = -1;
        
    while (option != 0)
    {
        /*
         * Menu of the animal shelter
         * Mandatory assignment (option 0 to 5)
         * Optional assignment (option 6)
         */
        printf("\nMENU\n====\n");
        printf("0: Quit program\n");
        printf("1: Show all animals\n");
        printf("2: Add an animal\n");
        printf("3: Search animals by name \n");
        printf("4: Update species by id\n");
        printf("5: Remove an animal by id\n");
        printf("6: Sort animals by species and name\n");

        scanf("%d", &option);
         
        switch(option)
        {
            // To do: add the code to be executed in each case
            case 0: 
                printf("Quit program\n");
                break;
            case 1: 
                show_animals(animals, number_of_animals);
                break;
            case 2: 
                Animal new_animal;
                add_animal(animals, &number_of_animals, new_animal);
                break;
            case 3: 
                search_animal_by_name(animals, number_of_animals);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                printf("ERROR: option %d is not available\n", option);
                break;
		}
	}
    return 0;
}