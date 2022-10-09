#include <stdio.h>

int main(void)
{
    int quotient, remainder, dig1,dig2,dig3,dig4,dig5;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d",&quotient);

    remainder = quotient % 8;
    dig1 = remainder;
    quotient /= 8;
    
    remainder = quotient % 8;
    dig2 = remainder;
    quotient /= 8;

    remainder = quotient % 8;
    dig3 = remainder;
    quotient /= 8;

    remainder = quotient % 8;
    dig4 = remainder;
    quotient /= 8;

    remainder = quotient % 8;
    dig5 = remainder;
    quotient /= 8;

    printf("In octal, your number is: %d%d%d%d%d", dig5, dig4, dig3, dig2, dig1);
    
    return 0;
}