#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 1st part of Assignment 1 SD */
void my_funct2(int arr_len, int * my_arr, int k_occ, int * outcome)
{	
	int * empty_arr = calloc(arr_len, sizeof(int));

	//fill new array with index of array
	for(int i = 0; i < arr_len; i++){
		empty_arr[my_arr[i]] += 1;
	}

	//loop through new array to find smallest number of K_OCC
	for(int i = 1; i < arr_len; i++){
		if(empty_arr[i] == k_occ){
			*outcome = i;
			break;
		}
	}
	
	free(empty_arr);
}

int main(int argc, char const *argv[]) {
	/* this is code to measure the time of your algorithm, please don't touch it */
    clock_t t; 
	double time_taken;
	t = clock(); 

	int arr_len;
	int k_occ;
	scanf("%d\n", &arr_len);
	int * my_arr = malloc(arr_len * sizeof(int));

	for(int i = 0; i < arr_len; i++){
		scanf("%d\t", &my_arr[i]);
	}
	scanf("%d\n", &k_occ);

	int outcome = 0;
	my_funct2(arr_len, my_arr, k_occ, &outcome);

	free(my_arr);

	/* this is the (performance) test code, please don't touch it */
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("minimum number of K occurences is %d\n", outcome);
#ifdef TEST_TIME
	printf("time needed was %f seconds\n", time_taken);
#endif
	return 0;
}
