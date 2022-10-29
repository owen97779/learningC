#include <stdio.h>
#define SIZE (sizeof(message) / sizeof(message[0]))

int main(void)
{
    char message[80] = {0},
    input;
    int i, shift;

    printf("Enter a message to be encrypted: ");
    for(i = 0; (input = getchar()) != '\n'; i++)
    {
        message[i] = input;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    printf("Encrypted message: ");
    for(i = 0; i < SIZE; i++)
    {
        if(message[i] <= 'Z' && message[i] >= 'A')
        {
            message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        }

        else if(message[i] <= 'z' && message[i] >= 'a')
        {
            message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }

        putchar(message[i]);
    }

    return 0;
}