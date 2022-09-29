#include <stdio.h>

int main(void)
{
    int itemNumber, day, month, year;
    float unitPrice;
    
    printf("Enter item number: ");
    scanf("%d", &itemNumber);
    
    printf("Enter unit price: ");
    scanf("%f", &unitPrice);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d /%d /%d",&month, &day, &year);

    printf("\nItem\tUnit\tPurchase\n\tPrice\tDate\n%d\t$%.2f\t%.2d/%.2d/%.4d\n",itemNumber,unitPrice,month,day,year);
    
    return 0;
}