#include <stdio.h>
#include <math.h>

int main(void)
{
    float deposit, interest;
    int years;
    
    printf("Enter deposit: ");
    scanf("%f", &deposit);
    printf("Enter interest rate as percentage: ");
    scanf("%f", &interest);
    printf("Enter number of years: ");
    scanf("%d", &years);

    double final = deposit * exp((interest / 100) * years);
    
    printf("$%.2lf\n", final);

    return 0;
}