#include <stdlib.h>
#include <stdio.h>
#include "../header/utils.h"
#include "../header/queues.h"
#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{

    struct QueueLinkedList*q=create_queue_linked_list();
    enqueLinkedList(q, 1);
    enqueLinkedList(q, 2);
    enqueLinkedList(q, 4);
    log_queue_linked_list(q);
    for (int count=1; count<=4;count++) {
    
        printf("\n item dequed is %d",dequeLinkedList(q));
    }
    return EXIT_SUCCESS;
}
