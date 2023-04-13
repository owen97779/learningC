#include <stdio.h>
#include <math.h>

void roots(double a, double b, double c)
{
    double x1, x2, discriminant = pow(b, 2.0) - 4 * a * c;

    if (discriminant > 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two solutions x = %lf, %lf\n", x1, x2);
    }
    else if (discriminant == 0)
    {
        x1 = -b / (2 * a);
        printf("Repeated solution x = %lf\n", x1);
    }
    else
    {
        printf("Roots are complex\n");
    }
}

int main(void)
{
    roots(1, -5, 6);
    roots(1, 2, 1);
    roots(1, 4, 5);

    return 0;
}