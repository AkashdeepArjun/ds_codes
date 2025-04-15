#include <stdio.h>
#include <stdlib.h>
#include "../header/utils.h"
#include "../header/array.h"
#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{
    
    int *arr=(int*) malloc(sizeof(int)*3);
        
    arr[0]=6;
    arr[1]=7;
    arr[2]=8;
    arr=realloc(arr, sizeof(int)*8);
    // arr[3]=99;
    // arr[4]=5;
    // arr[5]=9;
    // arr[6]=88;
    // arr[7]=108;
    log_array(arr, 8);

    return EXIT_SUCCESS;
}
