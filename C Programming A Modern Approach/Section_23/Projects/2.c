#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    while((c = getchar()) != EOF)
    {
        if(!isspace(c) && c != '\n')
            fputc(c, stdout);
    }
    return 0;
}