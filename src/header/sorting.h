#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED


#include "utils.h"
int partition(int*,int,int,struct AlgoBenchMark*);
void quick_sort(int*,int,int,struct AlgoBenchMark*);
void merge_sort(int*,int*,int ,int,struct AlgoBenchMark*);
void merge(int*,int*,int,int,int,struct AlgoBenchMark*);


#endif // !DEBUG
