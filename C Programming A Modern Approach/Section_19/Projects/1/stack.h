#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

//Use the linked list implementation

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, char input);
char pop(Stack s);

#endif