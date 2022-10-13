#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    if(number < 20 && number > 10)
    {
        switch (number%10)
        {
        case 1:
            printf("You entered the number eleven.");
            break;
        case 2:
            printf("You entered the number twelve.");
            break;
        case 3:
            printf("You entered the number thirteen.");
            break;
        case 4:
            printf("You entered the number fourteen.");
            break;
        case 5:
            printf("You entered the number fifteen.");
            break;
        case 6:
            printf("You entered the number sixteen.");
            break;
        case 7:
            printf("You entered the number seventeen.");
            break;
        case 8:
            printf("You entered the number eighteen.");
            break;
        case 9:
            printf("You entered the number nineteen.");
            break;
        default:
            break;
        }
    }
    
    else
    {
        switch (number / 10)
        {
        case 1:
            printf("You entered ten.");
            break;
        case 2:
            printf("You entered twenty");
            break;
        case 3:
            printf("You entered thirty");
            break;
        case 4:
            printf("You entered fourty");
            break;
        case 5:
            printf("You entered fifty");
            break;
        case 6:
            printf("You entered sixty");
            break;
        case 7:
            printf("You entered seventy");
            break;
        case 8:
            printf("You entered eighty");
            break;
        case 9:
            printf("You entered ninety");
            break;
        default:
            break;
        }

        switch (number % 10)
        {
        case 0:
            printf("\n");
            break;
        case 1:
            printf("-one.\n");
            break;
        case 2:
            printf("-two.\n");
            break;
        case 3:
            printf("-three.\n");
            break;
        case 4:
            printf("-four.\n");
            break;
        case 5:
            printf("-five.\n");
            break;
        case 6:
            printf("-six.\n");
            break;
        case 7:
            printf("-seven.\n");
            break;
        case 8:
            printf("-eight.\n");
            break;
        case 9:
            printf("-nine.\n");
            break;
        
        default:
            break;
        }
    }

    return 0;
    
}