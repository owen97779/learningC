#include <stdio.h>

int main(void)
{
    float income, tax;

    printf("Enter taxable income: ");
    scanf("%f",&income);

    if (income < 750)
    {
        tax = .01f * income;
    }
    else if (income < 2250)
    {
        tax = 7.50 + 0.02f*(income - 750);
    }
     else if (income < 3750)
    {
        tax = 37.50 + 0.03f*(income - 2250);
    }
    else if (income < 5250)
    {
        tax = 82.50 + 0.04f*(income - 3750);
    }
    else if (income < 7000)
    {
        tax = 142.50 + 0.05f*(income - 5250);
    }
    else if (income > 7000)
    {
        tax = 230 + 0.06f*(income - 7000);
    }

    printf("Tax due: $%.2f",tax);

    return 0;
}