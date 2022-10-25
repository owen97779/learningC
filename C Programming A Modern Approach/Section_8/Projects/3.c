#include <stdio.h>
#define ARRAYSIZE (sizeof(occurences) / sizeof(occurences[0]))

int main(void)
{
    int occurences[10] = {0},
    digit, i;
    long n;

    while(1)
    {
        printf("Enter a number: ");
        scanf("%ld", &n);
        if(n <= 0)
        {
            break;
        }

        printf("Digit:\t\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\nOccurences:\t");

        while(n > 0)
        {
            digit = n % 10;
            occurences[digit] += 1;
            n /= 10;
        }

        for(i = 0; i < ARRAYSIZE; i++)
        {
            printf("%d\t", occurences[i]);
        }
        printf("\n");
    }

    return 0;
}