#include <stdlib.h>
#include <stdio.h>

#include "../header/algos_sort.h"
#include "../header/array.h"
#define EXIT_SUCCESS 0



int main(int argc, char *argv[])
{       
    int random_size=gen_random_size(0,5);

    int*new_array=create_random_array(random_size);
    
    log_array(new_array,random_size);

    int comparison =  bubble_sort_improved(new_array,random_size);

    log_array(new_array, random_size);

    printf("\n  WITH SIZE = %d TOTAL COMPARISONS DONE %d\n ",random_size,comparison);

    return EXIT_SUCCESS;
}
