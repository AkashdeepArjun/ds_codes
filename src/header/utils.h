#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED


#include "array.h"
#include  "../header/utils.h"
struct AlgoBenchMark {

    int SWAPS;
    int COMPARISONS;
    
    
};

struct AlgoBenchMark* init_measure();

void take_log(char*);

void swap(int*,int,int);

void rand_init();
int gen_random_size(int, int);


#endif // !UTILS_H_INCLUDED
