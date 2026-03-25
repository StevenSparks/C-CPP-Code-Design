#include <decoder.h>
#include <encoder.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool check_intergrity_of_byte(uint8_t * encoded_byte){
    if(encoded_byte == NULL){
        return false;
    }
    
    //check if MSB is flipped
    if((*encoded_byte & (1 << 7)) != 0){
        //remove paritybits
        *encoded_byte = (*encoded_byte & 0b1111);
        return true;
    }

    //calculate if flipped parity is above 1
    uint8_t copy = (*encoded_byte & 0b1111);
    set_parity(&copy);

    uint8_t result = (copy ^ *encoded_byte);
    uint8_t result_copy = (result >> 4);

    int i = 0;
    int count = 0;
    while(i != 3){
        if((result_copy & 0b1) == 1){
            count++;
        }
        result_copy = (result_copy >> 1);
        i++;
    }
    
    switch(count){
        case 1:
            //parity flipped
            *encoded_byte = (*encoded_byte & 0b1111);
            break;
        case 2:
            //dataX flipped
            //011 = P0 and P1 = share commonality between D1
            //110 = P1 and P2 = share commonality between D2
            //101 = P2 and P0 = share commonality between D3
            //i could spend time to make this not pure degeneracy but i dont have the willpower anymore.
            switch(result >> 4){
                case 0b0011:
                    *encoded_byte = ((*encoded_byte & 0b1111) ^ (1 << 1));
                    break;
                case 0b0110:
                    *encoded_byte = ((*encoded_byte & 0b1111) ^ (1 << 2));
                    break;
                case 0b0101:
                    *encoded_byte = ((*encoded_byte & 0b1111) ^ (1 << 3));
                    break;
            }
            break;
        case 3:
            //data0 Flipped
            *encoded_byte = ((*encoded_byte & 0b1111) ^ 0b1);
            break;
        default:
            //supposed error
            break;
    } 

    return true;
}

bool reconstruct_byte(FILE *input_file, FILE *output_file){
    //this function should honestly just return a character pointer but i cant be asked anymore.
    if(input_file == NULL || output_file == NULL){
        return false;
    }

    char byte1 = 0;
    char byte2 = 0;
    while((byte1 = fgetc(input_file)) != EOF){
        //legal since byte2 cannot ever be EOF
        byte2 = fgetc(input_file);

        //please dont look at the build warnings regarding passing chars as ints
        check_intergrity_of_byte(&byte1);
        check_intergrity_of_byte(&byte2);

        char out = ((byte1 << 4) | byte2);
        fputc(out, output_file);
    }

    return true;
}