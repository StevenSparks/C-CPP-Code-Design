#include <encoder.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool set_parity(uint8_t * byte){
    if(byte == NULL){
        return false;
    }

    uint8_t p0 =0;
    uint8_t p1 =0;
    uint8_t p2 =0;

    //set P0 based on D0, D1, D3    
    p0 = (((*byte >> 3) ^ (*byte >> 1) ^ *byte) & 0b1); 
    //set P1 based on D0, D1, D2
    p1 = (((*byte >> 2) ^ (*byte >> 1) ^ *byte) & 0b1); 
    //set P0 based on D0, D2, D3
    p2 = (((*byte >> 3) ^ (*byte >> 2) ^ *byte) & 0b1); 

    *byte = *byte | (p0 << 4) | (p1 << 5) | (p2 << 6);

    return true;
}

bool encode_input_file(FILE *input_file, FILE *output_file){
    if(input_file == NULL || output_file == NULL){
        return false;
    }

    char c;
    while((c = fgetc(input_file)) != EOF){
        uint8_t msb = ((c & 0b11110000) >> 4);
        uint8_t lsb = (c & 0b1111);

        set_parity(&msb);
        set_parity(&lsb);

        fputc(msb, output_file);
        fputc(lsb, output_file);
    }

    return true;
}