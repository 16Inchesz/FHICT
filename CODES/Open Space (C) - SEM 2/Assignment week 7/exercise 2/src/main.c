#include <stdio.h>
#include <stdbool.h>

bool Search_value(int *a, int size_array, int value, bool* result){
    if(result == NULL || a == NULL){
        return false;
    }
    for (int i = 0; i < size_array; i++){
        if (a[i] == value){
            *result = true;
            return true;
        }
    }
    *result = false;
    return true;
}

bool calculate_occurences(int *a, int size_array, int value, int* occurrence){
    if(occurrence == NULL || a == NULL){
        return false;
    }
    for (int i = 0; i < size_array; i++){
        if (a[i] == value){
            *occurrence += 1;
        }    
    }
    return true;
}


int main()
{
    int a[] = {8, 3, 9, 7, 6, 5, 2, 1, 2};
    bool result;
    int value = 2;
    int occurence = 0;
    int size_array = sizeof(a)/sizeof(a[0]);

    // if (Search_value(a, size_array, value, &result)){
    //     if(result){
    //         printf("the value is in the array\n");
    //     } else {
    //         printf("this value is not in the array\n");
    //     }
    // } else {
    //     printf("pointer not provided\n");
    // }

    if (calculate_occurences(a, size_array, value, &occurence)){
        printf("this value occurs %d times\n", occurence);
    } else {
        printf("pointer not provided");
    }
    return 0;
}
