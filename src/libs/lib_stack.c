#include "../header/stack.h"
/*#include <cstddef>*/
#include <bits/types/stack_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../header/utils.h"
#include <assert.h>
#include <strings.h>
struct Stack* createStack(int capacity){

    /*take_log("creating stack ");*/
struct Stack*mystack = (struct Stack*)malloc(sizeof(struct Stack*));
assert(mystack!=NULL);  

mystack->top =-1;
mystack->capacity=capacity;
mystack->elements=(int *)malloc(sizeof(int)*capacity);
assert(mystack->elements!=NULL);

return mystack;


}
int is_stack_empty(struct Stack*stack){

    
    return stack->top==-1;


}




int push(struct Stack * storage, int new_element){
    
    if(storage->top==storage->capacity-1){
        printf("\n OVERFLOW STACK\n");
        return -1;
    } 
    storage->elements[++storage->top]=new_element;

    return 1;
    


}

int pop(struct Stack*storage){

        
    if (storage->top==-1) {
        
        printf("\n STACK UNDERFLOW \n");
        return -1;
    }

    return storage->elements[storage->top--];


}

 void log_stack(struct Stack *stack){
    
     int end_point=stack->top;
    
     for(int index=0;index<=end_point;index++){

         char*output=(index==0 && index==end_point)?"[ %d ]<=top":(index==0 && index!=end_point)?"[ %d,":(index<end_point)?"%d ,":"%d ] <= top";
         printf(output,stack->elements[index]);

     }
     printf("\n");
    

 }

void delete_stack(struct Stack *storage)
{

    if(storage){
        
        if(storage->elements){

            free(storage->elements);
        }
        
        free(storage);
    }


}
