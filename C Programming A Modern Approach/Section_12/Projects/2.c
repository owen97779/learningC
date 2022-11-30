#include <stdio.h>
#include <ctype.h>
#define LENGTH 100

int main(void)
{
    char a[LENGTH]; 
    int i = 0; 
    char *track, *p = a;
    char input;

    printf("Enter a message: ");
    
    while((input = toupper(getchar())) != '\n')
    {
        if(isalpha(input))
        {
            *p++ = input;
        }
        
    }

    for(track = a, p--; p > track; track++, p--)
    {
        
        if(*track != *p)
        {
            printf("Not a palindrome\n");
            break;
        }
    }

    if(p - track == 0)
    {
        printf("Palindrome\n");
    }

    return 0;
}