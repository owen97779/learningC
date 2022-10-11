#include <stdio.h>

int main(void)
{
    int number;
    
    printf("Enter a number: ");
    scanf("%d",&number);

    if (number <= 9 && number >= 0)
    {
        printf("Your number has 1 digit");
    }
    else if (number >= 10 && number <= 99)
    {
        printf("Your number has 2 digits");
    }
    else if (number >= 100 && number <= 999)
    {
        printf("Your number has 3 digits");
    } 
    else /*Obviously the user will only input a valid positive number :)*/
    {
        printf("Your number has 4 digits");
    }

    return 0;
}