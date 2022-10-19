#include <stdio.h>

int main(void)
{
    int input, i;
    /* Change type*/
    long double prevAnswer = 0, answer = 1;

    printf("Enter a positive number: ");
    scanf("%d", &input);

    for(i = 1; i <= input; i++)
    {
        if (prevAnswer > answer)
        {
            printf("Maximum n: %d\n", --i);
            break;
        }
        prevAnswer = answer;
        answer *=  i;
    }
    /*Change type for answer*/
    printf("Factorial of %d: %Lf", input, answer); 
    
    return 0;
}

/* Maximum n on my PC and compiler:
    short: 7
    int: 12
    long: 12
    long long: 20
    float: 34
    double: 170
    long double: 1754*/