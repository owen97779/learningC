#include <stdio.h>
#include <ctype.h>
#define SIZE ((int) (sizeof(input)) / (sizeof(input[0])))

int main(void)
{
    int i = 0;
    char input[50] = {0}, c;
    
    printf("Enter message: ");
    while((c = getchar()) != '\n')
    {
        input[i++] = c;
    }

    printf("In B1FF-speak: ");
    
    for(i = 0; i < SIZE; i++)
    {
        switch (toupper(input[i]))
        {
        case 'A':
            putchar('4');
            break;
        case 'B':
            putchar('8');
            break;
        case 'E':
            putchar('3');
            break;
        case 'I':
            putchar('1');
            break;
        case 'O':
            putchar('0');
            break;
        case 'S':
            putchar('5');
            break;
        
        default:
            putchar(toupper(input[i]));
            break;
        }
    }
    printf("!!!!!!!!!!\n");

    return 0;
    
}