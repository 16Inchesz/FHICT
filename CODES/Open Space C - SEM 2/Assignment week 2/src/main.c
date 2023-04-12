#include <stdio.h>
#include <string.h>

/*
//assingment 1
float FindMean(int arr1[], int size){
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr1[i];
    }
    return sum/size;
}

float FindMedian(int arr1[], int size){
    float median, temp;
    //bubble sort
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if(arr1[j] > arr1[j + 1]){
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    //calculate median for both even and uneven.
    if (size % 2 == 0){
        median = (arr1[size/2] + arr1[size/2-1])/2.0;
    } else {
        median = (arr1[size/2]);
    }
    return median;
}
int FindMode(int arr1[], int size){
    int i, j, count, max_count = 0, mode = 0;
    
    for (i = 0; i < size; i++){
        count = 0;
        for (j = 0; j< size; j++){
            if (arr1[j] == arr1[i]){
                count++;
            }
        }
        if (count > max_count){
            max_count = count;
            mode = arr1[i];
        }
    }
    return mode;
} 

int main()
{
    int arr1[10] = {5, 1, 2, 3, 2, 4, 5, 3, 5, 2 };
    int size = 10;
    double mean_value, median_value;
    int mode_value;

    mean_value = FindMean(arr1, size);
    median_value = FindMedian(arr1, size);
    mode_value = FindMode(arr1, size);

    printf("Mean: %.2f\n", mean_value);
    printf("Median: %.2f\n", median_value);
    printf("Mode: %d\n", mode_value);

    return 0;
}
*/  

//assignment 2
/*
void BinaryConvertion(int decimal, char binary[]){
    int i = 0;
    while (decimal > 0){
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0';
    strrev(binary); //reverse the string
}

int main(){
    int decimal;
    char binary[32];

    printf("enter a decimal number: ");
    scanf("%d", &decimal);

    BinaryConvertion(decimal, binary);
    printf("The binary conversion of %d is %s.\n", decimal, binary);
    return 0;
}
/*
int DecimalConversion(long long binary){
    int decimal = 0, base = 1, rem;
    while (binary > 0){
        rem = binary % 10;
        binary /= 10; 
        decimal += rem * base;
        base *= 2;
    }
    return decimal;
}

int main(){
    long long binary;
    int decimal;
    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    decimal = DecimalConversion(binary);

    printf("The decimal equivalent of %lld is %d.\n", binary, decimal);

    return 0;
}
*/
