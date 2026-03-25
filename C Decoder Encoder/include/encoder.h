#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool set_parity(uint8_t * byte);

bool encode_input_file(FILE *input_file, FILE *output_file);
#endif