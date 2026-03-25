#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 2nd part of Assignment 1 SD */

//part of qsort
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void my_funct(int arr_len, int * my_arr, int limiter, int * outcome){
	
	int sum_start = 0;
	int sum_end = 0;

	for(int i = 0; i < limiter; i++){
		sum_start += my_arr[i];
		sum_end += my_arr[(arr_len - 1) - i];
	}

	*outcome = (sum_end - sum_start);
}

int main() {
	/* this is code to measure the time of your algorithm, please don't touch it */

    clock_t t; 
	double time_taken;

    t = clock(); 
	
	int arr_len;
	int limiter;
	scanf("%d\n", &arr_len);
	int * my_arr = malloc(arr_len * sizeof(int));

	for(int i = 0; i < arr_len; i++){
		scanf("%d\t", &my_arr[i]);
	}
	scanf("%d\n", &limiter);
	int outcome = 0;

	qsort(my_arr, arr_len, sizeof(int), compare);

	/* implement her your code e.g. like this 
	 * o utcome= get_difference_between_min_and_max_sum_of_k_elems( choose your own arguments );
	 */
	my_funct(arr_len, my_arr, limiter, &outcome);

	free(my_arr);

	/* this is the (performance) test code, please don't touch it */
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("difference between minimum and maximum sum of K elements is %d\n", outcome);
#ifdef TEST_TIME
	printf("time needed was %f seconds\n", time_taken);
#endif
	return 0;
}
