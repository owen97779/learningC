#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE 100

float stack[STACK_SIZE];
int top = 0;

void stack_overflow(void);
void stack_underflow(void);
void RPN(void);

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
        stack[top++] = i;
    }
}

float pop(void)
{
    if (is_empty())
    {
        stack_underflow();
        return 0;
    }
    else
    {
        return stack[--top];
    }
}

int main(void)
{
    
    RPN();

    return 0;
}

void RPN(void)
{
    char input;
    float n1, n2; 

    for(;;)
    {
        printf("Enter an RPN expression: ");
        while((input = getchar()) != '\n')
        {
            switch (input)
            {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                push(input - '0');
                break;
            
            case '+': 
                push(pop() + pop());
                break;
            
            case '-': 
                n2 = pop();
                n1 = pop();
                push(n1 - n2);
                break;
            
            case '/':
                n2 = pop();
                n1 = pop();
                push(n1 / n2);
                break;
            
            case '*':
                push(pop() * pop());
                break;

            case '=':
                printf("Value of expression is %.2f\n", pop());

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

void stack_overflow(void) 
{
    printf("Expression is too complex\n");
    exit(1);
}

void stack_underflow(void) 
{
    printf("Not enough operands in expression\n");
    exit(1);
}