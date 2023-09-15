#include <stdio.h>
#include <time.h>
/* 1st part of Assignment 1 SD Johnson Domacasse*/ 

/// @brief Function to find the smallest number that occurs a specific amount of times
/// @param arr 
/// @param n 
/// @param k 
/// @return The smallest number that occurs exactly K amount of times.
int get_minimum_number_with_k_occurrences(int arr[], int n, int k) {
    //minimum num and how many times it has occured.
    int min = -1;
    int min_count = 0;

    //iterate through integers to get current integer.
    for (int i = 0; i < n; i++) {
        int current = arr[i];
        int count = 0;

        //count how many times the current number has been found in the array.
        for (int j = 0; j < n; j++) {
            if (arr[j] == current) {
                count++;
            }
        }

        //condition to check if the current number has appeared K number of times.
        if (count == k) {
            //update min if current is smaller than min.
            if (min == -1 || current < min) {
                min = current;
            }
        }
    }

    //return min
    return min;

}

int main() {
	/* this is code to measure the time of your algorithm, please don't touch it */

    	clock_t t; 
	double time_taken;

    	t = clock(); 

	//---------------------------------------------------------------------------------
	int outcome = 0;
	int n, k;

	//read list size N 
	scanf("%d", &n); 

	//go through array of integers 
	int arr[n];
	for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

	//read single input K 
	scanf("%d", &k); 

	//run algorithm.
    outcome = get_minimum_number_with_k_occurrences(arr, n, k);

	/* this is the (performance) test code, please don't touch it */
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("minimum number of K occurences is %d\n", outcome);
#ifdef TEST_TIME
	printf("time needed was %f seconds\n", time_taken);
#endif
	return 0;
}
