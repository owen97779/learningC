#include <stdio.h>
#include <math.h>

double polynomial(double);

int main(void)
{
    double x;

    printf("Enter a value for x: ");
    scanf("%lf", &x);
    printf("The value is %lf", polynomial(x));

    return 0;
}

double polynomial(double x)
{
    return (3 * pow(x, 3)) + (2 * pow(x, 4)) - (5 * pow(x, 3)) - (pow(x, 2)) + (7 * x) - 6;
}