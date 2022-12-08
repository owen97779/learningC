#include <stdio.h>
#define LENGTH 100

void reverse(char *message);

int main(void)
{
    char message[LENGTH];
    char *p = message;
    char input;

    printf("Enter a message: ");
    
    while((input = getchar()) != '\n')
    {
        *p++ = input;
    }

    reverse(message);
    
    printf("Reversal is: %s\n", message);

    return 0;
}

void reverse(char *message)
{
    char *p = message;
    char *q = message;
    char temp;

    while(*q)
    {
        q++;
    }
    q--;

    while(p < q)
    {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}