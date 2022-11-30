#include <stdio.h>
#define LENGTH 100

int main(void)
{
    int a[LENGTH], i = 0, *p;
    char input;

    printf("Enter a message: ");
    
    while((input = getchar()) != '\n')
    {
        a[i++] = input;
    }

    printf("Reversal is: ");
    for(p = a + i; p >= a; p--)
    {
        printf("%c", *p);
    }
    printf("\n");

    return 0;
}