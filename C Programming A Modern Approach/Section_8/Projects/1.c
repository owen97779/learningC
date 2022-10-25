#include <stdio.h>
#include <stdbool.h>
#define ARRAYSIZE (sizeof(repeated_digits) / sizeof(repeated_digits[0]))

int main(void)
{
    bool digit_seen[10] = {false}, 
    repeated_digits[10] = {false};
    int digit, i;
    long n;
    
    printf("Enter a number: ");
    scanf("%ld", &n);

    printf("Repeated digit(s): ");

    while(n > 0)
    {
        digit = n % 10;
        if(digit_seen[digit])
        {
            repeated_digits[digit] = true;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    for(i = 0; i < ARRAYSIZE; i++)
    {
        if(repeated_digits[i])
        {
            printf("%d ", i);
        }
    }

    return 0;
}
