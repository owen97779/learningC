#include <stdio.h>

float taxableIncome(float);

int main(void)
{

    float income, tax;

    printf("Enter taxable income: ");
    scanf("%f",&income);

    tax = taxableIncome(income);
    printf("Tax due: $%.2f", tax);

    return 0;
}

float taxableIncome(float income)
{
    if (income < 750)
    {
        return .01f * income;
    }
    else if (income < 2250)
    {
        return 7.50 + 0.02f*(income - 750);
    }
     else if (income < 3750)
    {
        return 37.50 + 0.03f*(income - 2250);
    }
    else if (income < 5250)
    {
        return 82.50 + 0.04f*(income - 3750);
    }
    else if (income < 7000)
    {
        return 142.50 + 0.05f*(income - 5250);
    }
    else if (income > 7000)
    {
        return 230 + 0.06f*(income - 7000);
    }
}