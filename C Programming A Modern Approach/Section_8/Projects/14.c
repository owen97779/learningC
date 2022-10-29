#include <stdio.h>

int main(void)
{
    char sentence[40] = {0},
    terminate, input;
    int i = 0, j, k;

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
            sentence[i++] = input;
            break;
        }
    }

    for(j = i; i >= 0; i--)
    {
        if(sentence[i] == ' ')
        {
            for(k = i + 1; k <= j; k++)
            {
                putchar(sentence[k]);
            }
            j = i - 1;
            printf(" ");
        }
    }

    for(i = 0; i <= j; i++)
    {
        putchar(sentence[i]);
    }
    printf("%c", terminate);

    return 0;
}