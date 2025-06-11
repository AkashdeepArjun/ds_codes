#include "../header/stack_bst.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define DEFAULT_STACK_SIZE 10


struct stackBst* init_stackbst(int capacity)
{
    
    struct stackBst*stack =(struct stackBst*)malloc(sizeof(struct stackBst));
    assert(stack!=NULL);
    stack->CAPACITY=capacity;
    stack->TOP=-1;
    stack->elements=(struct Bst**)malloc(sizeof(struct Bst*)*stack->CAPACITY);

    return stack;



}

int isBstStackFull(struct stackBst*stack){

    return stack->TOP==(stack->CAPACITY-1);


}

int isBstStackEmpty(struct stackBst*stack){



    return stack->TOP==-1;

}


struct Bst* pop(struct stackBst*stack){

    
    if(isBstStackEmpty(stack)){
        printf("\nSTACK IS EMPTY NOTHING TO POP HERE\n");
        return NULL;
    }else{

    struct Bst*popped_item = stack->elements[stack->TOP--];

    
    return popped_item;



    }

}

int push(struct stackBst*stack,struct Bst*node){

    if(isBstStackFull(stack)){
        printf("\n STACK IS FULL CANT DO PUSH OPERATION \n");
        return -1;
    }else{

        stack->elements[++stack->TOP]=node;
        return 1;
    }



}


void logStackBst(struct stackBst*stack){

    if(isBstStackEmpty(stack)){
        printf("\n NOTHING TO PRINT BYE ...\n");
    }else{
        int index=stack->TOP;
        while(index<=stack->CAPACITY-1) {
            if(index>=0 && index<stack->CAPACITY-1){
                printf("%d ->",(stack->elements[index])->data);
            }else{
                printf("%d <- TOP",(stack->elements[index])->data);
            }
            index++;

        }



    }
}












