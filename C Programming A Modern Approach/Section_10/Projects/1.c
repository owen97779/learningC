#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void stack_overflow(void);
void stack_underflow(void);

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char i)
{
    if (is_full())
    {
        stack_overflow();
    }
    else
    {
        contents[top++] = i;
    }
}

int pop(void)
{
    if (is_empty())
    {
        stack_underflow();
        return 0;
    }
    else 
    {
        return contents[--top];
    }
}

int main(void)
{
    char input;
    
    printf("Enter parentheses and/or braces: ");
    while((input = getchar()) != '\n')
    {
        if(input == '(' || input == '{')
        {
            push(input);
        }
        else if(input == ')' || input == '}')
        {
            pop();
        }
    }
    
    if(is_empty())
    {
        printf("The parentheses/braces are matched.\n");
    }
    else
    {
        printf("The parentheses/braces are not matched\n");
    }

    return 0;
}

void stack_overflow(void)
{
    printf("Warning, stackoverflow!\n");
    exit(1);
}

void stack_underflow(void)
{
    printf("The parentheses/braces are not matched.\n");
    exit(1);
}