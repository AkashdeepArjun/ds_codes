#include "../header/algos_sort.h"
#include "../header/utils.h"


int bubble_sort_improved(int*array,int size){

    int CYCLES=size-1;
    int EVENT_SWAP=1;
    int CYCLE=CYCLES;
    int COMPARISONS=0;
    while (CYCLE>=0 && EVENT_SWAP==1){
        EVENT_SWAP=0;
        for(int INDEX=0;INDEX<=CYCLE-1;INDEX++){

           if (array[INDEX]>array[INDEX+1]) {
                COMPARISONS+=1;
                swap(array,INDEX, INDEX+1);
                EVENT_SWAP=1;

           }else{
               COMPARISONS+=1;
           }

        }
        CYCLE--;


    }


    return COMPARISONS;



}



