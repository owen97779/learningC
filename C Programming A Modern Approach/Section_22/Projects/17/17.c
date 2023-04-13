#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    FILE *input_file;
    char first[4], second[4], third[5];
    int i = 0;
    char num;
    bool complete;

    if(argc != 2)
    {
        fprintf(stderr, "Error, input file not provided\n");
        exit(EXIT_FAILURE);
    }

    if(((input_file = fopen(argv[1], "r")) == NULL))
    {
        fprintf(stderr, "File %s could not be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while((num = fgetc(input_file)) != EOF)
    {
        if(isdigit(num) && i < 3)
        {
            first[i++] = num; 
        }
        if(i == 3)
        {
            first[i++] = '\0';
        }
        else if(isdigit(num) && i > 3 && i < 7)
        {
            second[i++ - 4] = num;
        }
        if(i == 7)
        {
            second[i++ - 4] = '\0';
        }
        else if(isdigit(num) && i > 7 && i < 12)
        {
            third[i++ - 8] = num;
        }
        if(i == 12)
        {
            third[i - 8] = '\0';
            complete = true;
        }
        if(complete)
        {
            printf("(%s) %s-%s\n", first, second, third);
            complete = false;
            i = 0;
        }

    }

    fclose(input_file);

    return 0;
}