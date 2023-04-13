#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> 

typedef int Item;
typedef struct queue_type *Queue;

void queue_append(Queue, Item i);
void queue_remove(Queue);
Item queue_head(Queue);
Item queue_last(Queue);
bool queue_is_empty(Queue);
Queue create(void);
void destroy(Queue);

#endif