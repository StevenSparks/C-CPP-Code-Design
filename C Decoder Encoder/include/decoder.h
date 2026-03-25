#ifndef DECODER_H
#define DECODER_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool check_intergrity_of_byte(uint8_t * encoded_byte);
bool reconstruct_byte(FILE *input_file, FILE *output_file);

#endif