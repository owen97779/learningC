#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char input;
    int vowels = 0;

    printf("Enter a sentence: ");

    while((input = getchar()) != '\n')
    {
        switch (toupper(input))
        {
        case 'A': case 'E': case 'I': case 'O': case 'U':
            vowels++;
            break;
        
        default:
            break;
        }
    }

    printf("Your sentence contains %d vowels", vowels);

    return 0;
}