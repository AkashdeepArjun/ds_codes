#include "../header/algos_sort.h"
#include "../header/utils.h"
void merge(int*,int*,int,int,int,struct AlgoBenchMark*);
void  merge_sort(int*ARRAY,int*RESULT,int LEFT_CURSOR,int RIGHT_CURSOR,struct AlgoBenchMark*benchmark){

    int MIDDLE_INDEX;
    if(RIGHT_CURSOR>LEFT_CURSOR){
            
        MIDDLE_INDEX=(LEFT_CURSOR+RIGHT_CURSOR)/2;
        merge_sort(ARRAY,RESULT,LEFT_CURSOR,MIDDLE_INDEX,benchmark);
        merge_sort(ARRAY,RESULT,MIDDLE_INDEX+1,RIGHT_CURSOR,benchmark);
        merge(ARRAY,RESULT,LEFT_CURSOR,MIDDLE_INDEX+1,RIGHT_CURSOR,benchmark);



    }
    
    




}
void merge(int*ARRAY,int*RESULT,int LEFT_CURSOR,int MIDDLE_INDEX,int RIGHT_CURSOR,struct AlgoBenchMark*benchmark){

    int LEFT_END=MIDDLE_INDEX-1;
    int CURSOR_RESULT=LEFT_CURSOR;
    int SIZE=RIGHT_CURSOR-LEFT_CURSOR+1;
    int LEFT_PTR=LEFT_CURSOR;
    int RIGHT_PTR=RIGHT_CURSOR;
    int MIDDLE_PTR=MIDDLE_INDEX;
    /*int *counter =COUNTER;*/

    while (LEFT_PTR<=LEFT_END && MIDDLE_PTR<=RIGHT_CURSOR) {

        if (ARRAY[LEFT_PTR]<=ARRAY[MIDDLE_PTR]) {
        
            RESULT[CURSOR_RESULT]=ARRAY[LEFT_PTR];
            benchmark->COMPARISONS++;

             CURSOR_RESULT++;
            /**counter=*counter+1;*/
            LEFT_PTR++;
        

        }else {
        benchmark->COMPARISONS++;
                
            RESULT[CURSOR_RESULT]=ARRAY[MIDDLE_PTR];

            CURSOR_RESULT++;
            /**counter+=1;*/
            MIDDLE_PTR++;
            

        }
            
    }

   while (LEFT_PTR<=LEFT_END) {
   
       RESULT[CURSOR_RESULT]=ARRAY[LEFT_PTR];
       CURSOR_RESULT++;
       LEFT_PTR++;
   }

   while (RIGHT_PTR<=RIGHT_CURSOR) {
       RESULT[CURSOR_RESULT]=ARRAY[RIGHT_PTR];
       CURSOR_RESULT++;
       RIGHT_PTR++;
   
   }

   for(int INDEX=LEFT_CURSOR;INDEX<LEFT_CURSOR+SIZE;INDEX++){

       ARRAY[INDEX]=RESULT[INDEX];
   }





}
