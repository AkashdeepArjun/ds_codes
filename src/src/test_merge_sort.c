#include "../header/algos_sort.h"
#include "../header/array.h"
#include <stdio.h>
#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{
    int counter=0;
    int *array =create_random_array(5);
    int *result=create_empty_array(5);
    struct AlgoBenchMark*benchmark = init_measure();
    printf("input array:");
    log_array(array,5);
    printf("\n");
    void*ptr=&counter;
    merge_sort(array, result ,0,4,benchmark);
    printf("output array:\n");
    log_array(array, 5);
    printf("%d COMPARISONS DONE\n",benchmark->COMPARISONS);

    return EXIT_SUCCESS;
}
