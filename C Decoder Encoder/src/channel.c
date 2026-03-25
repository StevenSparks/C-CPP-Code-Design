#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>

bool channel_inner_monkey(FILE *input_file, FILE *output_file){
    if(input_file == NULL || output_file == NULL){
        return false;
    }

    int my_max = 8;
    int my_min = 0;

    char c;
    while((c = fgetc(input_file)) != EOF){
        c ^= (1 << (rand() % my_max + my_min));
        fputc(c, output_file);
    }

    return true;
}   