#include <math.h>
#include <stdlib.h>
#include "../header/utils.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define INPUT_INT 'i';
#define INPUT_CHAR 'c';
#define INPUT_STRING 's';
#define INPUT_FLOAT 'f';
#define INPUT_DOUBLE 'b';
#define INPUT_ARRAY 'a';
void rand_init(){

    time_t t;
    srand((unsigned)time(NULL));

}


int gen_random_size(int min,int max){

    int random_num =(rand()%((max-min)+1))+min;
    return random_num;

}



struct AlgoBenchMark* init_measure(){

struct AlgoBenchMark*benchmark =(struct AlgoBenchMark*)malloc(sizeof(struct AlgoBenchMark));
benchmark->COMPARISONS=0;
benchmark->SWAPS=0;

return benchmark;



}


void take_log(char*message){

    void*ref_type;
    time_t raw_time;
    struct tm*timedata;

    time(&raw_time);

    timedata=localtime(&raw_time);

 



printf( "%s%b%s",asctime(timedata),message);


}

void swap(int*array,int index1,int index2){
    
    int temp=array[index1];
    array[index1]=array[index2];
    array[index2]=temp;

    
}
