#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char sentence[30][20], punct;
    char input;
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    while((input = getchar()) != '\n')
    {
        if(isspace(input))
        {
            sentence[i][j] = '\0';
            i++;
            j = 0;
            continue;
        }

        if(ispunct(input))
        {
            punct = input;
            sentence[i][j] = '\0';
            break;
        }

        else if(isalpha(input))
        {
            sentence[i][j++] = input;
        }

    }

    while(i > 0)
    {
        printf("%s ", sentence[i--]);
    }
    printf("%s%c\n", sentence[i], punct);

    return 0;
}