#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q1 = create();
    Queue q2 = create();
    
    //Add a couple items to q1
    //queue_remove(q1);
    queue_append(q1, 55);
    printf("q1 head:%d\tq1 tail:%d\n",queue_head(q1), queue_last(q1));
    queue_append(q1, 130);
    printf("q1 head:%d\tq1 tail:%d\n",queue_head(q1), queue_last(q1));
    queue_append(q1, 336);
    printf("q1 head:%d\tq1 tail:%d\n\n",queue_head(q1), queue_last(q1));

    queue_remove(q1);
    printf("q1 head:%d\tq1 tail:%d\n",queue_head(q1), queue_last(q1));
    queue_remove(q1);
    printf("q1 head:%d\tq1 tail:%d\n",queue_head(q1), queue_last(q1));
    queue_remove(q1);
    queue_append(q1, 123);
    printf("q1 head:%d\tq1 tail:%d\n",queue_head(q1), queue_last(q1));


    printf("q1 head: %d, q1 last: %d\n", queue_head(q1), queue_last(q1));
    //Add the head of q1 to q2;
    queue_append(q2, queue_head(q1));
    printf("q2 head = %d\n", queue_head(q2));

    //Remove the head of q1;
    queue_remove(q1);
    printf("q1 head: %d, q1 last: %d\n", queue_head(q1), queue_last(q1));

    //Is q1 empty? It shouldn't be
    if(!queue_is_empty(q1))
    while(!queue_is_empty(q1))
        queue_remove(q1);

    printf("q1 head: %d, q1 last: %d\n", queue_head(q1), queue_last(q1));
    
    queue_is_empty(q1) == true ? printf("q1 empty now\n") : printf("q1 not empty\n");
    //Destroy q2
    printf("q2 head: %d\nq2 last: %d\n", queue_head(q2), queue_last(q1));

    //destroy(q2);

    printf("q2 head: %d\nq2 last: %d\n", queue_head(q2), queue_last(q1));
    
    return 0;
    
}