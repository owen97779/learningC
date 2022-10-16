#include <stdio.h>

int main(void)
{
    float loan, interest, payment;
    int n, i;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    printf("Enter number of payments: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        loan = (loan - payment) + (loan * interest / 100.00f / 12.00f);
        printf("Balance after payment %d: $%.2f\n", i, loan);
    }

    return 0;
}