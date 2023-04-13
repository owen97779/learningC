#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int ch;

    if(argc < 2)
    {
        fprintf(stderr, "You have not linked any files to concatenate\n");
        exit(EXIT_FAILURE);
    }

    for(char **p = argv + 1; *p != NULL; p++)
    {
        if((fp = fopen(*p, "r")) == NULL)
        {
            fprintf(stderr, "File %s could not be opened\n", *p);
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        while((ch = fgetc(fp)) != EOF)
        {
            fprintf(stdout, "%c", ch);
        }
        fclose(fp);
    }

    fprintf(stdout, "\n");

    return 0;
}
