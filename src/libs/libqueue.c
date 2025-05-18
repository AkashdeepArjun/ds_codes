#include "../header/utils.h"
// #include <iterator>
// #include <cstddef>
#include<malloc.h>
#include "../header/queues.h"
#include <assert.h>
#include <signal.h>
#include <stdio.h>
struct Queue* create_empty_queue(int capacity){

struct Queue* new_queue= (struct Queue*)malloc(sizeof(struct Queue*));

assert(new_queue!=NULL);

new_queue->front=-1;

new_queue->rear = -1;

new_queue->occupied=0;

new_queue->capacity=capacity;

new_queue->elements=(int*) malloc(sizeof(int)*new_queue->capacity);

assert(new_queue->elements!=NULL);

return new_queue;
}

int isQueueFull(struct Queue*queue){
       
   
    return queue->occupied==queue->capacity;

}

int isQueueEmpty(struct Queue*queue){


    return queue->occupied==0;


}

int enque(struct Queue *queue, int item){

if(isQueueFull(queue)){
    printf("\n QUEUE IS FULL LOL");
    return  0;
}



if (isQueueEmpty(queue)) {
    
    queue->front=0;
}

queue->elements[++queue->rear]=item;
queue->occupied++;

return 1;


}

int deque(struct Queue *queue){

   // printf("\n CURRENT FRONT AT %d ",queue->front); 
    // printf("queue is \n");
    print_queue(queue);
    if (isQueueEmpty(queue)) {
    
        printf("\n QUEUE IS EMPTY LOL ");
        return 0;
    } 


     int data =queue->elements[queue->front];
     if (queue->front==queue->rear) {
        queue->front=-1;
        queue->rear=-1;
        queue->occupied=0;
     }else{
     queue->front++;
     queue->occupied--;

     }

     return data;

}


void print_queue(struct Queue*q){
    
    int index=q->front;
    int last_index=q->rear;
    printf("\n");
    while(index<=last_index){
    
        if(index>=0 & index<last_index){
            printf("%d ->",q->elements[index]);
        }else{
            printf("%d",q->elements[index]);
        }
        index++;

    }


}


struct CircularQueue* create_empty_circular_queue(int capacity){

    struct CircularQueue*new_queue =(struct CircularQueue*)malloc(sizeof(struct CircularQueue*));
    assert(new_queue!=NULL);
    new_queue->CAPACITY=capacity;
    new_queue->FRONT=-1;
    new_queue->REAR=-1;
    new_queue->OCCUPIED=0;
    new_queue->ELEMENTS=(int*)malloc(new_queue->CAPACITY*sizeof(int));
    assert(new_queue->ELEMENTS!=NULL);



    return  new_queue;


}
 int isCircularQueueEmpty(struct CircularQueue * queue){

     return  queue->OCCUPIED==0;

}

int isCircularQueueFull(struct CircularQueue * queue){
    
    return  queue->OCCUPIED==queue->CAPACITY;


}

int enque_circular_queue(struct CircularQueue *queue, int data){
   
        // printf("ENQUE CALLED !!!");

       
        printf("\n ENQUEING %d..........\n",data);

        if (isCircularQueueFull(queue)) {
            
            // printf("\n QUEUE IS FULL ");

            resize(queue);
                
            // return 0;

        }
        if (isCircularQueueEmpty(queue)) {
        
            queue->FRONT++;
    
        }
                
        //recent item at last position
        if(queue->REAR==queue->CAPACITY-1){
                
            queue->REAR=(queue->REAR+1)%queue->CAPACITY;
            queue->ELEMENTS[queue->REAR]=data;
            queue->OCCUPIED++; 
            return 1;

        }else{
                
            queue->ELEMENTS[++queue->REAR]=data;

            queue->OCCUPIED++; 
            return  1;


        }

         





}




int deque_circular_queue(struct CircularQueue *queue){

    // printf("DEQUE CALLED");
   
    printf("\n DEQUEING..\n");
    if (isCircularQueueEmpty(queue)) {
    
        printf("\n EMPTY QUEUE CAN NOT DEQUE");
        return 0;
    }

    int data = queue->ELEMENTS[queue->FRONT];
    queue->OCCUPIED--;
    if (queue->FRONT==queue->REAR) {
        
        queue->FRONT=-1;
        queue->REAR=-1;
        queue->OCCUPIED=0;
    }else if(queue->FRONT==queue->CAPACITY-1){
        
        queue->FRONT=(queue->FRONT+1)%queue->CAPACITY;
        


    }else{

        queue->FRONT++;
    }

    return  data;




}

void print_circular_queue(struct CircularQueue *q){

int start=q->FRONT<=q->REAR?q->FRONT:q->REAR;
    int end=q->FRONT>=q->REAR?q->FRONT:q->REAR;
    // int end=q->CAPACITY-1;
    printf("\n RESULT IS: ");
    while(start<=end){
    
        if(start>=0 & start<end){
            printf("%d ->",q->ELEMENTS[start]);
        }else{
            printf("%d\n",q->ELEMENTS[start]);
        }
        start++;

    }



}


void log_circular_queue(struct CircularQueue*q){

    if(q->FRONT>q->REAR){
            
        int start=q->FRONT;

        while(start>=q->REAR)
        {
                
            if(start==q->REAR){
                printf("\n%d",q->ELEMENTS[start]);
            }
            else{
                printf("%d->",q->ELEMENTS[start]);
            }

            start--;

        }




    }else{

        int start=q->FRONT;

        while(start<=q->REAR)
        {
                
            if(start==q->REAR){
                printf("\n%d",q->ELEMENTS[start]);
            }
            else{
                printf("%d->",q->ELEMENTS[start]);
            }

            start++;



        }

    }

}




int resize(struct CircularQueue*q){

    int offset_size=q->CAPACITY;
    q->CAPACITY=2*q->CAPACITY;
    q->ELEMENTS=realloc(q->ELEMENTS,sizeof(int)*q->CAPACITY);
    if (!q->ELEMENTS) {
        printf("\n COULD NOT RESIZE QUEUE \n");
        return 0;
    }
    if(q->FRONT>q->REAR){
        
        for (int index=0;index<q->FRONT ; index++) {
            
            q->ELEMENTS[index+offset_size]=q->ELEMENTS[index];

        }

        q->REAR=q->REAR+offset_size;


    }

    return  1;
}

// linkedlist queue 
 struct QueueNode* createQueueNode(int item){

     struct QueueNode*queue_node = (struct QueueNode*)malloc(sizeof(struct QueueNode*));
    assert(queue_node!=NULL);
    queue_node->INFO=item;
    queue_node->NEXT=NULL;
    return queue_node;
 }

struct QueueLinkedList* create_queue_linked_list(){

    
     struct QueueLinkedList*queue = (struct QueueLinkedList*)malloc(sizeof(struct QueueLinkedList*));
    assert(queue!=NULL);
    queue->FRONT=NULL;
    queue->REAR=NULL;
    return queue; 




}

 int isEmptyLinkedListQueue(struct QueueLinkedList * queue){

    
     return (queue->FRONT==NULL && queue->REAR==NULL);


 }

int queue_size_linked_list(struct QueueLinkedList *queue){
   int SIZE=0;
   struct QueueNode* begin=queue->FRONT;
   
   while (begin!=NULL) {
    
       SIZE++;
       begin =begin->NEXT;

   }

   return SIZE;


}

int enqueLinkedList(struct QueueLinkedList *queue,int item){
    printf("\nENQUEING %d",item);
    struct QueueNode*queue_node=createQueueNode(item);
    if(queue->REAR==NULL){
       
        queue->REAR=queue_node;
    }else{
        queue->REAR->NEXT=queue_node;
        queue->REAR=queue_node;
    }

    if (queue->FRONT==NULL) {
    
        queue->FRONT=queue->REAR;
    }

    return 1;

}

int dequeLinkedList(struct QueueLinkedList *q){

    if (!queue_size_linked_list(q)) {
        
        printf("\nQUEUE IS EMPTY");
        
        return 0;
    }else {
            
        int d= q->FRONT->INFO;
        if(q->FRONT==q->REAR){
            q->REAR=NULL;
            q->FRONT=NULL;
           }else{

        q->FRONT=q->FRONT->NEXT;
           }
        
        return d;
    }


} 

void log_queue_linked_list(struct QueueLinkedList *q){

    struct QueueNode*start=q->FRONT;
    printf("QUEUE \n");
    while(start!=NULL){
            
        if(start->NEXT==NULL){
            printf("\%d",start->INFO);
        }else{
            printf("%d->",start->INFO);
        }

        start=start->NEXT;

    }

    printf("\n");




}
