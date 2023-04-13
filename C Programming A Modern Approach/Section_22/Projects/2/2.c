#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int ch;

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "File cannot be opened\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF)
    {
        fprintf(stdout, "%c", toupper(ch));
    }
    fclose(fp);

    fprintf(stdout, "\n");

    return 0;
}