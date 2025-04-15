#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include "../header/utils.h"

int* create_empty_array(int size){

    int*arr_new = (int*)malloc(sizeof(int));

    return arr_new;



}


int* create_random_array(int size){

    int *arr_ref=(int*)malloc(size*sizeof(int));
    rand_init();
    for(int index=0;index<size;index++){
        

        arr_ref[index]=rand()%101;

        //Logiic rand()%[max-min+1]+min


    }
return arr_ref;
}

void print_array(int * arr,int size){

   for(int i=0;i<size;i++){

       printf("[%d]=>%d\n",i,arr[i]);


   }    




}

void log_array(int* array,int size){
    
    printf("[ ");
    for (int i=0;i<size;i++) {
    if(i==size-1){
    printf("%d",array[i]);
    }else {
    
        printf("%d,",array[i]);
    }
    }
    printf(" ]\n");


}
