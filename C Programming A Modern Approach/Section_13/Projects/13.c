#include <stdio.h>
#define SIZE (sizeof(message) / sizeof(message[0]))

void encrypt(char *message, int shift);

int main(void)
{
    char message[80] = {0}, input;
    int shift;

    printf("Enter a message to be encrypted: ");
    for(int i = 0; (input = getchar()) != '\n'; i++)
    {
        message[i] = input;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);
    
    return 0;
}

void encrypt(char *message, int shift)
{
    while(*message)
    {
        if(*message <= 'Z' && *message >= 'A')
        {
            *message = ((*message) - 'A' + shift) % 26 + 'A';
        }

        else if(*message <= 'z' && *message >= 'a')
        {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        }
        
        message++;
    }
}