#include <stdio.h>

int main(void)
{
    int number;
    char *tens[] = {"twenty", "thirty", "forty",
                    "fifty", "sixty", "seventy"
                    "seventy", "eighty", "ninety"};

    char *teens[] = {"ten", "eleven", "twelve", "thirteen",
                    "fourteen", "fifteen", "sixteen",
                    "seventeen", "eighteen", "nineteen"};

    char *units[] = {"", "-one", "-two", "-three",
                        "-four", "-five", "-six",
                        "-seven", "-eight", "-nine"};

    printf("Enter a two-digit number: ");
    scanf("%2d", &number);

    if(number / 10 == 1)
    {
        printf("You entered: %s\n", teens[number % 10]);
    }
    else
    {
        printf("You entered: %s%s\n", tens[number / 10 - 2], units[number % 10]);
    }    

    return 0;  
}