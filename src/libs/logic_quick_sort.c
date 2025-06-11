#include "../header/array.h"
#include "../header/utils.h"
int partition(int*,int,int,struct AlgoBenchMark*);

void quick_sort(int*A,int start,int end,struct AlgoBenchMark*benchmark){

    if(start<end){
        
    int pivot_position= partition(A, start,end,benchmark);
    quick_sort(A,start,pivot_position-1,benchmark);
    quick_sort(A , pivot_position+1, end,benchmark);



    }




}



int partition(int*A,int start,int end,struct AlgoBenchMark*benchmark){

    int left = start;
    int right = end;
    int pivot=A[start];

    while(left<right){
    
        while(A[left]<=pivot){

        

            benchmark->COMPARISONS+=1;

            left++;   

        }

        while(A[right]>pivot){

            benchmark->COMPARISONS+=1;
            right--;


        }

        if(left<right){
            swap(A, left, right);
            benchmark->SWAPS+=1;

        }
    }
    
    A[start]=A[right];
    A[right]=pivot;

    return right;


}
