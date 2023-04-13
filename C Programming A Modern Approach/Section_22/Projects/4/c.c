#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int ch;
    unsigned long int new_lines = 0;

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "File cannot be opened\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
        {
            new_lines++;
        }

    }
    fclose(fp);
    
    // +1 in the new_lines variable because it does not include EOF
    fprintf(stdout, "Number of lines in %s: %lu\n", argv[1], new_lines + 1);

    return 0;
}