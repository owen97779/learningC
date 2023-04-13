#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    FILE *fp1, *fp2;
    unsigned long int read_bytes;
    unsigned char read_buffer[BUFFER_SIZE];
    unsigned char write_buffer[BUFFER_SIZE * 2];

    if(argc != 2)
    {
        fprintf(stderr, "Error, not provided file\n");
        exit(EXIT_FAILURE);
    }

    char output_filename[strlen(argv[1]) + 5]; // Add space for ".rle"
    strcpy(output_filename, argv[1]); // Copy input filename to output filename
    strcat(output_filename, ".rle"); // Append ".rle" to output filename

    if(((fp1 = fopen(argv[1], "rb")) == NULL) || ((fp2 = fopen(output_filename, "wb")) == NULL))
    {
        fprintf(stderr, "Error, file %s could not be opened and create a rle file", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_bytes = fread(read_buffer, sizeof(read_buffer[0]), sizeof(read_buffer) / sizeof(read_buffer[0]), fp1)))
    {
        unsigned char constant = read_buffer[0];
        unsigned char count = 1;
        unsigned long int k = 0;

        for(int i = 1; i < read_bytes; i++)
        {
            if(read_buffer[i] == constant)
            {
                if(count == 255)
                {
                    write_buffer[k++] = count;
                    write_buffer[k++] = constant;
                    count = 0;
                }
                count++;
            }
            else
            {
                write_buffer[k++] = count;
                write_buffer[k++] = constant;
                constant = read_buffer[i];
                count = 1;
            }
        }

        write_buffer[k++] = count;
        write_buffer[k++] = constant;

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
