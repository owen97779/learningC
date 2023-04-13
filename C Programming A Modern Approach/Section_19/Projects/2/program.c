#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"

void RPN(void);

int main(void)
{
    
    RPN();

    return 0;
}

void RPN(void)
{
    char input;
    float n1, n2;
    Stack s = create(); 

    for(;;)
    {
        printf("Enter an RPN expression: ");
        while((input = getchar()) != '\n')
        {
            switch (input)
            {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                push(s, input - '0');
                break;
            
            case '+': 
                push(s, pop(s) + pop(s));
                break;
            
            case '-': 
                n2 = pop(s);
                n1 = pop(s);
                push(s, n1 - n2);
                break;
            
            case '/':
                n2 = pop(s);
                n1 = pop(s);
                push(s, n1 / n2);
                break;
            
            case '*':
                push(s, pop(s) * pop(s));
                break;

            case '=':
                printf("Value of expression is %.2f\n", pop(s));

            case ' ':
                break;
            
            case '\n':
                break;

            default:
                exit(1);
            }
        }
    }
}
