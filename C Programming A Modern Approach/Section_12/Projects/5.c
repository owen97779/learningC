#include <stdio.h>

int main(void)
{
    char sentence[40] = {0},
    terminate, input, *p = sentence, *q;

    printf("Enter a sentence: ");
    while((input = getchar()) != '\n')
    {
        switch (input)
        {
        case '.':
            terminate = '.';
            break;
        case '?':
            terminate = '?';
            break;
        case '!':
            terminate = '!';
            break;
        
        default:
            *p++ = input;
            break;
        }
    }

    printf("Reversal: \n");

    while(p > sentence)
    {
        while(*--p != ' ' && p != sentence);
        
        q = p == sentence ? sentence : p + 1;
        
        while(*q != ' ' && *q != '\0')
        {
            putchar(*q++);
        }
        
        if(p > sentence)
        {
            printf(" ");
        }
    }

    printf("%c", terminate);

    return 0;
}