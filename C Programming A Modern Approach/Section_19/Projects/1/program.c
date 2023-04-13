#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(void)
{
    char input;
    Stack s = create();
    
    printf("Enter parentheses and/or braces: ");
    while((input = getchar()) != '\n')
    {
        if(input == '(' || input == '{')
        {

            push(s, input);
        }
        else if(input == ')' || input == '}')
        {
            pop(s);
        }
    }
    
    if(is_empty(s))
    {
        printf("The parentheses/braces are matched.\n");
    }
    else
    {
        printf("The parentheses/braces are not matched\n");
    }

    return 0;
}
