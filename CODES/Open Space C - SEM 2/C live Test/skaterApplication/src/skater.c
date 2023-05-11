#include "skater.h"

bool update_score_by_name(Skater *skaters, int number_of_skaters, char first_name[], int new_score){
    //check for null input
    if(skaters == NULL){
        return false;
    }
    
    //check if there are indeed skaters.
    if (number_of_skaters <= 0){
        return false;
    }

    // to check first_name was not found
    bool name_found = false;

    //update the score of the skater if found
    for (int i = 0; i < number_of_skaters; i++){
        if (strcmp(skaters->first_name, first_name) == 0){
            skaters->score = new_score;
            name_found = true;
        }
        skaters++;
    }

    //if skater was not found
    if (name_found == false){ 
        return false; 
    }

    return true;
}

bool search_winner(Skater *skaters, int number_of_skaters, Skater *winner){
    //check for null input
    if(skaters == NULL || winner == NULL){
        return false;
    }
    
    //check if there are indeed skaters
    if (number_of_skaters <= 0){
        return false;
    }

    //variables for highest score.
    int highest = 0;

    //find the highest score first
    for (int i = 0; i < number_of_skaters; i++){
        if ((skaters)->score > (skaters+1)->score){
            highest = skaters->score;
        }
        skaters++;
    }

    //compare highest score with the players, when player is found, he is the winner
    for (int i = 0; i < number_of_skaters; i++){
        if ((skaters)->score == highest){
            winner->score = skaters->score;         //tried changing to skaters*
        }
        skaters++;
    }

    return true;
}

bool find_youngest_performer(Skater *skaters, int number_of_skaters, Skater *youngest_performer){
    //cehck for null input
    if(skaters == NULL || youngest_performer == NULL){
        return false;
    }
    
    //check if there are indeed skaters
    if (number_of_skaters <= 0){
        return false;
    }

    //bubble sort the skaters age first
    for (int i = 0; i < number_of_skaters - 1; i++) {
        for (int j = 0; j < number_of_skaters - i - 1; j++) {
            if ((skaters+j)->age > (skaters+j+1)->age) {  
                Skater temp = *(skaters+j);
                *(skaters+j) = *(skaters+j+1);
                *(skaters+j) = temp;
            }
        }
    }

    //using bubble sort to check for players age and to see if their score is highest.
    for (int i = 0; i < number_of_skaters - 1; i++) {
        for (int j = 0; j < number_of_skaters - i - 1; j++) {
            if (((skaters+j)->age == (skaters+j+1)->age) && ((skaters+j)->score > (skaters+j+1)->score )) {    
                *youngest_performer = *skaters;     //tried swapping then assigning it to first in the struct.
            }
        }
    }
    return true;
}
