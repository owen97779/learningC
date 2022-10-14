#include <stdio.h>

int main(void)
{
    float number = 0.0f, 
    largest = 0.0f;
    
    do
    {
        printf("Enter a number: ");
        scanf("%f", &number);
        if (number > largest)
            largest = number;
    } while (number>0);
    
    printf("The largest number entered was: %f", largest);

    return 0;
}