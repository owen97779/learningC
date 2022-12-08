#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define LENGTH 100

bool is_palindrome(const char *message);

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

    is_palindrome(a) ? printf("Palindrome\n") : printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(const char *message)
{
    const char *p = message;
    const char *q = message;

    while(*q)
    {
        q++;
    }
    q--;

    for(;p < q; p++, q--)
    {
        if(*p != *q)
        {
            return false;
        }
    }

    return true;
}