#include <stdio.h>

int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The reversed number is: ");

    do
    {
        printf("%d", num % 10);
        num /= 10;
    } while (num != 0);
    
    return 0;
}