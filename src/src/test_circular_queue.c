#include <stdio.h>
#include<stdlib.h>
#include "../header/utils.h"
#include "../header/queues.h"
#define EXIT_SUCCESS 0


int main(int argc, char *argv[])
{
    rand_init();
    // int size =gen_random_size(3, 5);
    int size=3;
    printf("QUEUE GENERATED OF SIZE %d",size);
    struct CircularQueue*q = create_empty_circular_queue(size);
    
    printf("\n TESTING DEQUE ON EMPTY QUEUE");
    
    int item = deque_circular_queue(q);
    printf("\n  TESTING ENQUE");

    for(int count =1;count<=size;count++){

        int num =gen_random_size(1, 5);
        printf("\n ENQUE %d",num);
        // enque(q,num);
        
        enque_circular_queue(q, num);

    }

   print_circular_queue(q); 

   // printf("REAR IS %d",q->REAR);
    
   int i =deque_circular_queue(q);
   printf("\n dequeued item is %d",i);

   int j =deque_circular_queue(q);
   printf("\n dequeued item is %d",j);


    int k =deque_circular_queue(q);
   printf("\n dequeued item is %d",k);



   // printf("REAR IS %d",q->REAR);
   print_circular_queue(q);


   enque_circular_queue(q, 5);
    

   printf("\n printing queue....");
    

   print_circular_queue(q);


    return EXIT_SUCCESS;
}
