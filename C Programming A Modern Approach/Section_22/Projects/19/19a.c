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

    if(((windows = fopen(argv[1], "rb")) == NULL) || ((unix = fopen(argv[2], "wb")) == NULL))
    {
        fprintf(stderr, "Files could not be opened\n");
        exit(EXIT_FAILURE);
    }

    while((c = fgetc(windows)) != EOF)
    {
        if(c != '\x0d')
        {
            fputc(c, unix);
        }
    }

    fclose(windows);
    fclose(unix);

    return 0;
}