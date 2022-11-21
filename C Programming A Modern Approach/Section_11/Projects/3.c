#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int numerator, denomenator, n, m;
    
    printf("Enter a fraction: ");
    scanf("%d /%d", &numerator, &denomenator);

    n = numerator;
    m = denomenator;

    reduce(numerator, denomenator, &n, &m);

    printf("In lowest terms: %d/%d\n", numerator / m, denomenator / m);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int r; 
    *reduced_numerator = numerator;
    *reduced_denominator = denominator;

    while (*reduced_numerator != 0)
    {
        r = *reduced_denominator % *reduced_numerator;
        *reduced_denominator = *reduced_numerator;
        *reduced_numerator = r;
    }
    
}
