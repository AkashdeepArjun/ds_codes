#include <bits/types/stack_t.h>
#include <stdio.h>
#include <stdlib.h>
#include "../header/array.h"
#define EXIT_SUCCESS0 
#include "../header/stack.h"
#include "../header/utils.h"
void test_push(struct Stack*,int);
void test_pop(struct Stack*);
void test_delete_stack(struct Stack*);
int main(int argc, char *argv[])
{
  
    rand_init();
    
    int SIZE =gen_random_size(3, 5);


    printf("generating RANDOM SIZE  %d OF STACK \n",SIZE);

    struct Stack*stack_object=createStack(SIZE);

    test_push(stack_object, SIZE);

    printf("\nTESTING POP OPERATION NOW");
    

    /*test_delete_stack(stack_object);*/
    test_pop(stack_object);

    printf("\n DELETING STACK.....");

    /*log_array(stack->elements,stack->top+1);*/
    
   

    return EXIT_SUCCESS;
}

void test_push(struct Stack*stack_object,int SIZE){
      
            
    printf("\n TESTING PUSH IN STACK BEYOND SIZE\n");

    for (int item=1 ;item<=SIZE+1;item++){
       
        int new_item =gen_random_size(1,5);
        
        printf("\n NUMBER GENERATED IS :%d\n",new_item);
        printf("\n pushing item %d ....\n",new_item);
        int status=push(stack_object,new_item);
        status==1?log_stack(stack_object):printf("OVERFLOW ERROR OCCURED\n");
        
    } 
        




}

void test_delete_stack(struct Stack*stack_object){

    delete_stack(stack_object);
    log_stack(stack_object);

}

void test_pop(struct Stack*stack_object){
    
    
    while(stack_object->top!=-1){
        
        int item = pop(stack_object);
        printf("\n POPPED ITEM IS %d \n",item);
        log_stack(stack_object);


    }
      
    pop(stack_object);

    



}
