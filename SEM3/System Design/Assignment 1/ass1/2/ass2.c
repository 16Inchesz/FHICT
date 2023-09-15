#include <stdio.h>
#include <time.h>
/* 2nd part of Assignment 1 SD Johnson Domacasse*/
//reference used: geekforgeeks.org/quicksort

//swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//partition function for quicksort
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//quick sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int get_difference_between_min_and_max_sum_of_k_elems(int arr[], int N, int K){
	//sort array
	quickSort(arr, 0, N - 1); 

	int minimumSum = 0;
	int maximumSum = 0;

	//calculate minimum sum
	for (int i = 0; i < K; i++) {
        minimumSum += arr[i];
    }

	//calculate maximum sum
	for (int i = N - 1; i >= N - K; i--) {
        maximumSum += arr[i];
    }

	return maximumSum - minimumSum;
}

int main() {
	/* this is code to measure the time of your algorithm, please don't touch it */
    clock_t t; 
	double time_taken;
	t = clock(); 

	int outcome = 0;
	int N, K;
	//read list size N 

	scanf("%d", &N); 

	//go through array of integers 
	int arr[N];
	for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

	//read single input K 
	scanf("%d", &K); 

	
	//run algorithm
	outcome = get_difference_between_min_and_max_sum_of_k_elems(arr, N, K);

	/* this is the (performance) test code, please don't touch it */
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("difference between minimum and maximum sum of K elements is %d\n", outcome);
#ifdef TEST_TIME
	printf("time needed was %f seconds\n", time_taken);
#endif
	return 0;
}
