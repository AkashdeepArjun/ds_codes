#include <stdio.h>
#include <stdlib.h>
#include "../header/utils.h"
#include "../header/queues.h"
#define EXIT_SUCCESS 0


int main(int argc, char *argv[])
{
    rand_init();
    int size =gen_random_size(3, 5);
    printf("QUEUE GENERATED OF SIZE %d",size);
    struct Queue*q = create_empty_queue(size);
    
    printf("\n TESTING DEQUE ON EMPTY");
    
    int item = deque(q);
    printf("\n  TESTING ENQUE");

    for(int count =1;count<=size+1;count++){

        int num =gen_random_size(1, 5);
        printf("\n ENQUE %d",num);
        enque(q,num);


    }

    // print_queue(q);

    printf("\n  TESTING DEQUEE");
    

  for(int count =1;count<=size+1;count++){

        int item=deque(q);
        printf("\n ITEM IS %d \n",item);



    }
    

    


    return EXIT_SUCCESS;
}
