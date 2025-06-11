#define EXIT_STATUS 0
#include<stdlib.h>
#include<stdio.h>
#include "../header/utils.h"
#include "../header/sorting.h"

void test_sorting(char*, int*,int);

int main(){

rand_init();


int sorted_desc[] ={5,4,3,2,1};

int sorted_asc[]={1,2,3,4,5};

int*random_array =create_random_array(5); 

int*test_asc = &sorted_asc[0];

int*test_desc = &sorted_desc[0];

test_sorting("SORTED ASC", sorted_asc, 5 );
test_sorting("SORTED DESC", sorted_desc, 5 );
test_sorting("RANDOM", random_array, 5 );



return EXIT_STATUS;

}

void test_sorting(char*type_array,int*array,int size){
    
    struct AlgoBenchMark*benchmark = init_measure();
    printf("INPUT SORTING ARRAY IS %s",type_array);
    log_array(array,size);
    quick_sort(array, 0, size-1, benchmark);
    printf("RESULT ARRAY IS ");
    log_array(array,size);

    printf("\n COMPARISONS :%d, SWAPS: %d\n",benchmark->COMPARISONS,benchmark->SWAPS);

    printf("\nresetting benchmarks....\n");
   
    if(benchmark){
        free(benchmark);
    }


}


