#include "../header/algos_sort.h"
#include "../header/utils.h"

int  bubble_sort(int *array ,int size)
{
int COMPARISONS=0;
int CYCLES=size-1;

for(int CYCLE=0;CYCLE<CYCLES;CYCLE++){

    for(int INDEX=0;INDEX<size-CYCLE-1;INDEX++){

        if(array[INDEX]>array[INDEX+1]){
            /*COMPARISONS+=1;*/
            swap(array, INDEX, INDEX+1);
            COMPARISONS+=1;
            /*SWAPS+=1;*/
        }else{
            COMPARISONS+=1;
        }


    }
} 
return  COMPARISONS;

}



