#include <stdio.h>

int power(int, int);

int main(void)
{
    int x, n;

    printf("Enter value for x and n: ");
    scanf("%d %d", &x, &n);

    printf("Value for %d ** %d is: %d\n", x, n, power(x,n));
}

int power(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n % 2 == 0)
    {
        return power(x, n / 2) * power(x, n / 2);
    }
    else
    {
        return x * power(x, n - 1);
    }
}