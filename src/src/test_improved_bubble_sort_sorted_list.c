#include "../header/algos_sort.h"
#include "../header/array.h"
#include <stdio.h>
#define EXIT_SUCCESS 0
int main(int argc, char *argv[])
{
    
    int data[]={-1,2,3,8};
    int *arr=&data[0];
    printf("array Provided :");
    log_array(arr, 4);
    printf("sorting array using bubble sort\n");
    int comparisons =bubble_sort_improved(arr, 4);
    printf("\n array result ");
    log_array(arr,4);
    printf("\n COMPARISONS DONE %d",comparisons);
    return EXIT_SUCCESS;
}
