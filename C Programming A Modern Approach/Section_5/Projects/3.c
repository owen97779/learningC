#include <stdio.h>

int main(void)
{
    int nShares;
    float price, commission, rivalComission, value;

    printf("Enter the number of shares: ");
    scanf("%d", &nShares);
    printf("Enter the price per share: $");
    scanf("%f", &price);

    value = nShares * price;

    if (value < 2500.00f)
    {
        commission = 30.00f + .017f * value;
        if (commission < 39.00f)
        {
            commission = 39.00f;
        }
    }
    else if (value < 6250.00f)
    {
        commission = 56.00f + .0066f * value;
    }
    else if (value < 20000.00f)
    {
        commission = 76.00f + .0034f * value;
    }
    else if (value < 50000.00f)
    {
        commission = 100.00f + .0022f * value;
    }
    else if (value < 500000.00f) 
    {
        commission = 155.00f + .0011f * value;
    }
    else
    {
        commission = 255.00f + .0009f * value;
    }

    printf("Commission: $%.2f\n", commission);

    if (nShares < 2000)
        rivalComission = 33.00f + .03f * nShares;
    else 
        rivalComission = 33.00f + .02f * nShares;

    printf("Rival comission: $%.2f", rivalComission);

    return 0;

}