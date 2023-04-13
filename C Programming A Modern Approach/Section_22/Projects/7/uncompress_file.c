#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;
    unsigned long int read_bytes;
    unsigned char read_buffer[BUFFER_SIZE * 2];
    unsigned char write_buffer[BUFFER_SIZE];

    if(argc != 2)
    {
        fprintf(stderr, "Error, not provided file\n");
        exit(EXIT_FAILURE);
    }

    char *input_filename = argv[1];
    while(*input_filename++);
    while(input_filename >= argv[1] && *input_filename != '.')
    {
        input_filename--;
    } 
    if((strcmp(input_filename, ".rle")) != 0)
    {
        fprintf(stderr, "Error, rle file not provided\n");
        exit(EXIT_FAILURE);
    }

    char *output_filename = malloc(strlen(argv[1]) - 4);
    strncpy(output_filename, argv[1], strlen(argv[1]) - 4);

    if(((fp1 = fopen(argv[1], "rb")) == NULL) || ((fp2 = fopen(output_filename, "wb")) == NULL))
    {
        fprintf(stderr, "Error, file %s could not be opened and create a rle file", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_bytes = fread(read_buffer, sizeof(read_buffer[0]), sizeof(read_buffer) / sizeof(read_buffer[0]), fp1)))
    {
        int k = 0;
        for(int i = 0; i < read_bytes; i++)
        {
            unsigned char count = read_buffer[i++];
            for(int j = 0; j < count; j++)
            {
                write_buffer[k++] = read_buffer[i];
            }
        }

        unsigned long int write_bytes = fwrite(write_buffer, sizeof(write_buffer[0]), k, fp2);
        if (write_bytes != k) 
        { //Checks if fwrite failed
            fprintf(stderr, "Error writing to output file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;

}