#include <stdio.h>

int main(void)
{
    char input, firstLetter;

    printf("Enter a first and last name: ");
    scanf(" %c", &firstLetter);

    while((input = getchar()) != ' ');

    while ((input = getchar()) != '\n')
    {
        switch (input)
        {
        case ' ':
            break;
        
        default:
            putchar(input);
            break;
        }
    }
    
    printf(", %c", firstLetter);

    return 0;
}
