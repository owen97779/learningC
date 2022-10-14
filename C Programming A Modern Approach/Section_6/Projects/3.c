#include <stdio.h>

int main(void)
{
    int numerator, denomenator, n, m, r;
    
    printf("Enter a fraction: ");
    scanf("%d /%d", &numerator, &denomenator);

    n, m = numerator, denomenator;

    while(n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }

    printf("In lowest terms: %d/%d", numerator / m, denomenator / m);

    return 0;
}