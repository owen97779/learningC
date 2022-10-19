#include <stdio.h>

int main(void)
{
    float operand, value;
    char input;

    printf("Enter an expression: ");
    scanf(" %f", &value);
    while((input = getchar()) != '\n')
    {
        switch (input)
        {
        case '*':
            scanf(" %f", &operand);
            value *= operand;
            break;
        case '/':
            scanf(" %f", &operand);
            value /= operand;
            break;
        case '+':
            scanf(" %f", &operand);
            value += operand;
            break;
        case '-':
            scanf(" %f", &operand);
            value -= operand;
            break;
        default:
            break;
        }
    }
    printf("Value of expression: %f", value);

    return 0;
}