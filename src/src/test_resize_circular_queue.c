#include <stdlib.h>
#include <stdio.h>
#include "../header/queues.h"
#include "../header/utils.h"
#define EXIT_SUCCESS 0


int main(int argc, char *argv[])
{
    int num=9;
    struct CircularQueue*queue=create_empty_circular_queue(3);
    enque_circular_queue(queue,6 );
    enque_circular_queue(queue,7 );
    enque_circular_queue(queue,8 );
    
    print_circular_queue(queue);

    for (int count =1; count<=2; count++) {
    int item = deque_circular_queue(queue);
    printf("\n ITEM FETCHED IS %d",item);
    
    }

    print_circular_queue(queue);

    for (int count =1; count<=2; count++) {
        enque_circular_queue(queue, num);
        num++;



    }

    print_circular_queue(queue);

    printf("\n LETS TRY TO ADD 11 \n");

    enque_circular_queue(queue, 11);

    print_circular_queue(queue);


    


    return EXIT_SUCCESS;
}
