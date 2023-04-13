#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node{
    Item data;
    struct node *next;
};

struct queue_type{
    struct node *head;
    
};

Queue create()
{
    Queue q;
    if((q = malloc(sizeof(struct queue_type))) == NULL)
    {
        printf("malloc error\n");
        exit(EXIT_FAILURE);
    }
    q->head = NULL;
    return q;
}

void destroy(Queue q)
{
    make_empty(q);
    free(q);
    q = NULL;
}

void queue_append(Queue q, Item i)
{
    struct node *n = malloc(sizeof(struct node));
    if(n == NULL)
    {
        printf("Error, malloc error\n");
        exit(EXIT_FAILURE);
    }
    n->data = i;
    n->next = NULL;

    if(q->head == NULL) //If empty list
    {
        q->head = n;
    }
    else
    {
        struct node *p = q->head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
    }
}

void queue_remove(Queue q)
{
    if(queue_is_empty(q))
    {
        printf("Queue is already empty\n");
        exit(EXIT_FAILURE);
    }
    struct node *new_head = malloc(sizeof(struct node));
    if(new_head == NULL)
    {
        printf("Malloc error\n");
        exit(EXIT_FAILURE);
    }
    new_head = q->head->next;
    free(q->head);
    q->head = new_head;
}

Item queue_head(Queue q)
{
    return q->head->data;
}

Item queue_last(Queue q)
{
    struct node *p = q->head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}

bool queue_is_empty(Queue q)
{
    return q->head == NULL;
}

void make_empty(Queue q)
{
    struct node *next = q->head;
    while(next != NULL)
    {
        struct node *prev = next;
        next = next->next;
        free(prev);
    }
    q->head = NULL;
}

/*bool queue_is_full(Queue q)
{
    return q->len == q->maxSize;
}*/