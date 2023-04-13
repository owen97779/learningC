#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int ch;
    unsigned long int number_of_characters = 0;

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "File cannot be opened\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(isgraph(ch))
        {
            number_of_characters++;
        }
    }
    fclose(fp);

    fprintf(stdout, "Number of characters in %s: %lu\n", argv[1], number_of_characters);

    return 0;
}