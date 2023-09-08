#ifndef SKATER_H
#define SKATER_H

//libraries
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

//constants
#define MAX_NAME_SIZE 20 
#define MAX_NUMBER_SKATERS 100

//skater struct
typedef struct{
    char first_name[MAX_NAME_SIZE];
    int age;
    int score;
}Skater;

/// @brief this function updates the score the players whose name is passed.
/// @param skaters 
/// @param number_of_skaters 
/// @param first_name 
/// @param new_score 
/// @return True on function success (false on depending on different circumstances)
bool update_score_by_name(Skater* skaters, int number_of_skaters, char first_name[], int new_score);

/// @brief this function searches for the winner by looking for the highest score than associating that highest score with its player.
/// @param skaters 
/// @param number_of_skaters 
/// @param winner 
/// @return True on function success (false on depending on different circumstances)
bool search_winner(Skater* skaters, int number_of_skaters, Skater* winner);

/// @brief this function bubble sorts the skaters age and then checks which skater among the youngest is the youngest performer.
/// @param skaters 
/// @param number_of_skaters 
/// @param youngest_performer 
/// @return True on function success (false on depending on different circumstances)
bool find_youngest_performer(Skater* skaters, int number_of_skaters, Skater* youngest_performer);

#endif