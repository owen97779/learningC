#include <stdio.h>

int main(void)
{
    float moneys = 0.0f;
    printf("Enter an amount: ");
    scanf("%f",&moneys);
    
    printf("With tax added: %.2f", moneys*1.05f);
    
    return 0;
}