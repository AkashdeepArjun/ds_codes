#include "../header/array.h"
#include "../header/utils.h"
#include "../header/sorting.h"

void merge_sort(int*data, int *result, int start, int end, struct AlgoBenchMark *benchmark){


    if(start<end){
        int mid =(start+end)/2;
        merge_sort(data,result,start,mid,benchmark);
        merge_sort(data,result,mid+1,end,benchmark);
        merge(data, result, start, mid+1, end, benchmark);
    }




}

void merge(int* data ,int *result, int start, int middle, int end, struct AlgoBenchMark * benchmark){
    int l=start;
    int r= end;
    int m=middle;
    int left_end=middle-1;
    int right_end =end;
    int size=end-start+1;
    int pos=start;
    while((l<=left_end) && (m<=right_end)){
       
        benchmark->COMPARISONS+=1;
        if (data[l]<=data[m]) {
            result[pos]=data[l];
            pos++;
            l++;
        }else{
            
            result[pos]=data[m];
            pos++;
            m++;
        }



    }

    while(l<=left_end){
        result[pos]=data[l];
        pos++;
        l++;
    }

    while(m<=right_end){
        
        result[pos]=data[m];
        pos++;
        m++;



    }

    for (int index=start;index<=end;index++) {
        data[index]=result[index];
    }



}
