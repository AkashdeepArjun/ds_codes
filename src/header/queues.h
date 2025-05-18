

struct Queue{
    
    int front;
    int rear;
    int occupied;
    int capacity;
    int *elements;


    
}; 


struct CircularQueue{
    
    int FRONT;
    int REAR;
    int OCCUPIED;
    int CAPACITY;
    int *ELEMENTS;
};


struct QueueNode{
    
    int INFO;
    struct QueueNode*NEXT;


};


struct QueueLinkedList{

   struct QueueNode*FRONT;
   struct QueueNode*REAR;
};
            // linked list queue
            
struct QueueNode* createQueueNode(int);

struct QueueLinkedList* create_queue_linked_list();

int isEmptyLinkedListQueue(struct QueueLinkedList*);

int isFullLinkedListQueue(struct QueueLinkedList*);

int enqueLinkedList(struct QueueLinkedList*,int);

int dequeLinkedList(struct QueueLinkedList*);
        
void log_queue_linked_list(struct QueueLinkedList*);

int queue_size_linked_list(struct QueueLinkedList*);

    
            //circular queue


struct CircularQueue* create_empty_circular_queue(int);

int enque_circular_queue(struct CircularQueue*,int);

int deque_circular_queue(struct CircularQueue*);

int isCircularQueueFull(struct CircularQueue* );

int isCircularQueueEmpty(struct CircularQueue*);

void print_circular_queue(struct CircularQueue*);

void log_circular_queue(struct CircularQueue*);

int resize(struct CircularQueue*);



struct Queue* create_empty_queue(int);

int enque(struct Queue*,int);

int deque(struct Queue*);

int isQueueFull(struct Queue* );

int isQueueEmpty(struct Queue*);

void print_queue(struct Queue*);
