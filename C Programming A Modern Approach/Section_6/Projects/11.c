#include <stdio.h>

int main(void)
{
    int n, i, j;
    float e, k;
    
    printf("Value for n: ");
    scanf("%d", &n);

    for(i = 1, e = 1.0f, k = 1.0f; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            k *= j;
        }
        e += 1 / k;
        k = 1;
    }

    printf("Value for e: %f", e);

    return 0;
}