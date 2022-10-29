#include <stdio.h>
#define SIZE ((sizeof(lastname))/sizeof(lastname[0]))

int main(void)
{
    char lastname[20] = {0}, 
    input, firstLetter;
    int i = 0;

    printf("Enter a first and last name: ");
    scanf(" %c", &firstLetter);

    while((input = getchar()) != ' ');

    while ((input = getchar()) != ('\n'))
    {
       lastname[i++] = input;
    }
    
    printf("You entered the name: ");
    for(i = 0; i < SIZE; i++)
    {
        printf("%c", lastname[i]);
    }

    printf(", %c", firstLetter);

    return 0;
}
