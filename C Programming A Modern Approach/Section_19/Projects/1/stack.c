#include "stack.h"
#define PUBLIC
#define PRIVATE static

#include <stdio.h>
#include <stdlib.h>

struct node{
    char input;
    struct node *next;
};

struct stack_type{
    struct node *top;
};

Stack create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if(s == NULL)
    {
        printf("Error in malloc to create Stack\n");
        exit(EXIT_FAILURE);
    }

    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while(!is_empty(s))
    {
        pop(s);
    }
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false; // Linked list.
}

void push(Stack s, char input)
{
    struct node *new_node = malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("Error in malloc to create node\n");
        exit(EXIT_FAILURE);
    }
    new_node->input = input;
    new_node->next = s->top;
    s->top = new_node;
}

char pop(Stack s)
{
    struct node *old_top;
    char input;
    
    if(is_empty(s))
    {
        printf("The parenthesis/braces are not matched\n");
        exit(EXIT_SUCCESS);
    }

    old_top = s->top;
    input = old_top->input;
    s->top = old_top->next;
    free(old_top);
    return input;
}

