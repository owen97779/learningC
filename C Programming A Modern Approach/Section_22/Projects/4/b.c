#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int ch;
    bool character = false;
    bool punc_control = false;
    unsigned long int words = 0;

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "File cannot be opened\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(isalpha(ch) || isdigit(ch))
        {
            character = true;
        }
        else if(isspace(ch) || ispunct(ch))
        {
            punc_control = true;

            if(character)
            {
                words++;
                character = false;
                punc_control = false;
            }
        }

    }
    fclose(fp);

    fprintf(stdout, "Number of words in %s: %lu\n", argv[1], words);

    return 0;
}