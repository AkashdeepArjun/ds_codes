#ifndef ALGOS_SORT_H_INCLUDED
#define ALGOS_SORT_H_INCLUDED

#include "utils.h"
int  bubble_sort(int*,int);
int  bubble_sort_improved(int*,int);
void insertion_sort(int*,int);
void selection_sort(int*,int);
void merge_sort(int*,int*,int,int,struct AlgoBenchMark*);
void quick_sort(int*,int);

#endif // !DEBUG
