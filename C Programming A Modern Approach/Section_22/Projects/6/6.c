#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER_SIZE 10

int main(int argc, char **argv)
{
    FILE *fp;
    unsigned long int read_bytes;
    unsigned long int offset = 0;
    unsigned char buffer[BUFFER_SIZE];

    if(argc != 2)
    {
        fprintf(stderr, "Error, not provided file\n");
        exit(EXIT_FAILURE);
    }

    if(((fp = fopen(argv[1], "rb")) == NULL))
    {
        fprintf(stderr, "Error, file %s could not be opened", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");

    while ((read_bytes = fread(buffer, sizeof(buffer[0]), sizeof(buffer) / sizeof(buffer[0]), fp)))
    {
        printf("%6lu  ", offset);
        for(int i = 0; i < read_bytes; i++)
        {
            printf("%.2X ", buffer[i]);
        }

        //Aligns the character output to the right column if read_bytes != BUFFER_SIZE
        if(read_bytes == BUFFER_SIZE)
        {
            printf(" ");
        }
        else
        {
            int prints = read_bytes;
            while(prints != 0)
            {
                printf("  ");
                prints -= 1;
            }
            printf(" ");
        }

        for(int i = 0; i < read_bytes; i++)
        {
            if(isprint(buffer[i]))
            { 
                printf("%c", buffer[i]);
            }
            else
            {
                printf(".");
            }
           
        }
        printf("\n");
        offset += 10;
    }

    fclose(fp);

    return 0;
}