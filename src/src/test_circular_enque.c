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

    printf("\nLETS ENQUE BEYOND SIZE\n");
    
    enque_circular_queue(q, 10);


    return EXIT_SUCCESS;
}
