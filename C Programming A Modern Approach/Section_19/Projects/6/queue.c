#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


struct queue_type{
    Item *contents;
    int first;
    int next;
    int len;
    int maxSize;
};

Queue create(int maxSize)
{
    Queue q;
    if((q = malloc(sizeof(struct queue_type))) == NULL)
    {
        printf("malloc error\n");
        exit(EXIT_FAILURE);
    }
    if((q->contents = malloc(sizeof(Item) * maxSize)) == NULL)
    {
        printf("malloc error\n");
        exit(EXIT_FAILURE);
    }

    q->first = 0;
    q->next = 0;
    q->len = 0;
    q->maxSize = maxSize;
    return q;
}

void destroy(Queue q)
{
    free(q->contents);
    free(q);
}

void queue_append(Queue q, Item i)
{
    if(queue_is_full(q))
    {
        printf("Error, max queue size\n");
        exit(EXIT_FAILURE);
    }
    q->contents[q->next] = i;
    q->next++;
    q->len++;
}

void queue_remove(Queue q)
{
    if(q->len == 0)
    {
        printf("Error, queue is already empty\n");
        exit(EXIT_FAILURE);
    }
    q->first++;
    q->len--;
}

Item queue_head(Queue q)
{
    return q->contents[q->next - 1];
}

Item queue_last(Queue q)
{
    return q->contents[q->first];
}

bool queue_is_empty(Queue q)
{
    return q->len == 0;
}

bool queue_is_full(Queue q)
{
    return q->len == q->maxSize;
}