#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *windows, *unix;
    char c;

    if(argc != 3)
    {
        fprintf(stderr, "Error, file not provided\n");
        exit(EXIT_FAILURE);
    }

    if(((unix = fopen(argv[1], "rb")) == NULL) || ((windows = fopen(argv[2], "wb")) == NULL))
    {
        fprintf(stderr, "Files could not be opened\n");
        exit(EXIT_FAILURE);
    }

    while((c = fgetc(unix)) != EOF)
    {
        if(c == '\x0a')
        {
            fputc('\x0d', windows);
        }
        fputc(c, windows);
    }

    fclose(unix);
    fclose(windows);

    return 0;
}