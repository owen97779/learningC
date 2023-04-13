# Section 19 Exercise Solutions

### 1. A queue is similar to a stack, except that items are added at one end but removed from other in a FIFO fashion. Operations in a queue might include:
### Inserting an item at the end of the queue
### Removing an item from the beginning of the queue
### Returning the first item in the queue (without changing the queue)
### Returning the last item in the queue (without changing the queue)
### Testing whether the queue is empty
### Write an interface for a queue module in the form of a header file named `queue.h`

    #ifndef QUEUE_H
    #define QUEUE_H

    #include <stdbool.h> 

    typedef int Item;
    typedef struct queue_type *Queue;

    void queue_append(Queue, Item i);
    void queue_remove_head(Queue);
    Item queue_head(Queue);
    Item queue_last(Queue);
    bool queue_is_empty(Queue);

    #endif

### 2. Modify the `stack.c` file to use PUBLIC and PRIVATE macros.

### 3. a) Write an array based implementation of the queue module described in Exercise 1. Use three integers to keep track of the queue's status, with one integer storing the position of the first empty slot in the array (used when an item is inserted), the second storing the position of the next item to be removed, and the third storing the number of items in the queue. An isertion or removal that would caused either of the first two integers to be incremented past the end of the array should instead reset the variable to zero, thus causing it to "wrap around" to the beginning of the array.

