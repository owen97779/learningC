#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char input;

    while((input = getchar()) != EOF)
    {
        if(!iscntrl(input) || input == '\n')
        {
            fputc(input, stdout);
        }
        else
        {
            fputc('?', stdout);
        }
    }

    return 0;
}