#include <stdio.h>
#include <stdbool.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

bool Search_value(int *a, int size_array, int value, bool* result){
    if(result == NULL || a == NULL){
        return false;
    }
    for (int i = 0; i < size_array; i++){
        if (*a == value){
            *result = true;
            return true;
        }
        a++;
    }
    *result = false;
    return true;
}

bool calculate_occurences(int *a, int size_array, int value, int* occurrence){
    if(occurrence == NULL || a == NULL){
        return false;
    }
    for (int i = 0; i < size_array; i++){
        if (*a == value){
            *occurrence += 1;
        } 
        a++;   
    }
    return true;
}


bool reverse_order(int *a, int size_array){
    if(a == NULL){
        return false;
    }
    for (int i = 0; i < size_array / 2; i++){
        //swap(*a, *(a+size_array - i - 1))
        swap(&a[i], &a[size_array - i - 1]);    
    }
    return true;
}

bool bubble_sort(int *a, int size_array){
    if(a == NULL){
        return false;
    }
    for (int i = 0; i < size_array - 1; i++){
        int *pa = a;
        for (int j = 0; j < size_array - i - 1; j++){
            if (*pa > *(pa + 1)){
                swap(pa, (pa + 1));
            }
            pa++;
        }
    }
    return true;    //when use exchange and when bubble.
}


int main()
{
    int a[] = {8, 3, 9, 7, 6, 5, 2, 1, 2};
    bool result;
    int value = 2;
    int occurence = 0;
    int size_array = sizeof(a)/sizeof(a[0]);

    if (Search_value(a, size_array, value, &result)){
        if(result){
            printf("the value is in the array\n");
        } else {
            printf("this value is not in the array\n");
        }
    } else {
        printf("pointer not provided\n");
    }

    if (calculate_occurences(a, size_array, value, &occurence)){
        printf("this value occurs %d times\n", occurence);
    } else {
        printf("pointer not provided");
    }

    if (reverse_order(a, size_array)){
        for (int i = 0; i < size_array; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    if (bubble_sort(a, size_array)){
        for (int i = 0; i < size_array; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
