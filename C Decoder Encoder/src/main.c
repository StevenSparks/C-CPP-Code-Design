#include <encoder.h>
#include <channel.h>
#include <decoder.h>
#include <file_writer.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

void print_my_menu(){
    printf("What would you like to do with these files?\n");
    printf("0: encode\n");
    printf("1: jargle\n");
    printf("2: decode\n");
}

void main_userchoice_encode(char const *input_file_name, char const *output_file_name)
{
    FILE *inputFile;
    FILE *outputFile;
    
    inputFile = fopen(input_file_name, "r");
    outputFile = fopen(output_file_name, "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Error: file cannot be opened");
        exit(EXIT_FAILURE); // Program is terminated
    }

    if (encode_input_file(inputFile, outputFile))
    {
        printf("encoding succes\n");
    }

    fclose(inputFile);
    fclose(outputFile);
}

void main_userchoice_jargle(char const *input_file_name, char const *output_file_name){
    FILE *inputFile;
    FILE *outputFile;
    inputFile = fopen(input_file_name, "r");
    outputFile = fopen(output_file_name, "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Error: file cannot be opened");
        exit(EXIT_FAILURE); // Program is terminated
    }

    srand(time(NULL));

    if (channel_inner_monkey(inputFile, outputFile))
    {
        printf("jargling succes\n");
    }

    fclose(inputFile);
    fclose(outputFile);
}

void main_userchoice_decode(char const *input_file_name, char const *output_file_name){
    FILE *inputFile;
    FILE *outputFile;
    inputFile = fopen(input_file_name, "rb");
    outputFile = fopen(output_file_name, "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        printf("Error: file cannot be opened");
        exit(EXIT_FAILURE); // Program is terminated
    }

    if(reconstruct_byte(inputFile, outputFile)){
        printf("yippie\n");
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char const *argv[])
{
    int user_mode = -1;
    print_my_menu();
    
    do
    {
        scanf("%d", &user_mode);
        switch (user_mode)
        {
        case 0:
            // encode
            main_userchoice_encode(argv[1], argv[2]);
            break;
        case 1:
            // jargle
            main_userchoice_jargle(argv[1], argv[2]);
            break;
        case 2:
            // decode
            main_userchoice_decode(argv[1], argv[2]);
            break;
        default:
            printf("nope!\n");
            break;
        }
    } while (user_mode != 0);

    return 0;
}
