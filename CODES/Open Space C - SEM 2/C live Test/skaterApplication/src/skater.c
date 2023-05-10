#include "skater.h"

bool update_score_by_name(Skater *skaters, int number_of_skaters, char first_name[], int new_score){
    
    if(skaters == NULL){
        return false;
    }
    
    if (number_of_skaters <= 0){
        return false;
    }

    // to check first_name was not found
    int count = 0;

    for (int i = 0; i < number_of_skaters; i++){
        if (skaters->first_name == first_name){
            skaters->score = new_score;
            count++;
        }
        skaters++;
    }

    if (count == 0){
        return false;
    }

    return true;
}

