#include <file_writer.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool write_array_as_file(FILE * output_file, uint8_t * my_arr, int arr_size){
    if(output_file == NULL || my_arr == NULL){
        return false;
    }

    for(int i = 0; i < arr_size; i++){
        fputc(my_arr[i], output_file);
    }
    return true;
}

bool write_file_as_array(FILE * input_file, uint8_t * my_output_arr, int * my_arr_size){
    if(input_file == NULL || my_output_arr == NULL){
        return false;
    }

    char c;
    while((c = fgetc(input_file)) != EOF){
        *my_output_arr = c;
        my_output_arr++;
        *my_arr_size += 1;
    }

    return true;
}