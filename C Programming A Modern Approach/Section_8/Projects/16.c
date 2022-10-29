#include <stdio.h>
#include <ctype.h>
#define SIZE (sizeof(letters)/sizeof(letters[0]))

int main(void)
{
    char input;
    int letters[26] = {0},
    i;

    printf("Enter first word: ");
    while((input = toupper(getchar())) != '\n')
    {
        if(isalpha(input))
        {
            letters[input - 'A'] += 1;
        }
    }

    printf("Enter second word: ");
    while ((input = toupper(getchar())) != '\n')
    {
        if(isalpha(input))
        {
            letters[input - 'A'] -= 1;
        }
    }
    
    for(i = 0; letters[i] == 0; i++);
    
    if(i == SIZE)
    {
        printf("The words are anagrams.");
    }
    else
    {
        printf("The words are not anagrams.");
    }

    return 0;
}