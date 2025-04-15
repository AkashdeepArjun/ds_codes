#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
#include "../header/queues.h"
#include "../header/utils.h"



int main(int argc, char *argv[])
{
    rand_init();
    struct CircularQueue*q = create_empty_circular_queue(3);
    for (int count =1; count<=3; count++) {
    
        int num =gen_random_size(1, 6);
        enque_circular_queue(q, num);

    }
    print_circular_queue(q);

   for (int count =1; count<=3; count++) {
    
        
       int item =deque_circular_queue(q);
       printf("\n ITEM DEQUEUD :%d\n",item);

    }

   printf("LETS TRY TO DEQUE IF QUEUE IS EMPTY");

   deque_circular_queue(q);
    
    


    return EXIT_SUCCESS;
}
