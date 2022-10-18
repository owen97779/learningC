/*Prints a table of squares using a for statement*/

#include <stdio.h>

int main(void)
{
    short int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        printf("%10hd%10hd\n", i, i * i);

    return 0;
}

/* When using shorts, the largest value for n is 181 as a 
signed short integer has a range -32,768 to +32,767 on my PC*/