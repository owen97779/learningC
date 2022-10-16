#include <stdio.h>

int main(void)
{
    int i, j;
    float e, k, n, currentTerm;

    printf("Small floating-point number: ");
    scanf("%f", &n);

    for(i = 1, e = 1.0f, k = 1.0f, currentTerm = 1.0f; currentTerm >= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            k *= j;
        }
        currentTerm = 1 / k;
        e += currentTerm;
        k = 1;
    }

    printf("Value for e: %f", e);

    return 0;
}