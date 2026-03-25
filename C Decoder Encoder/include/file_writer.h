#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool write_array_as_file(FILE * output_file, uint8_t * my_arr, int arr_size);

bool write_file_as_array(FILE * input_file, uint8_t * my_output_arr, int * my_arr_size);

#endif