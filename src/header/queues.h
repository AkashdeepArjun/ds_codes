

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


    
            //circular queue


struct CircularQueue* create_empty_circular_queue(int);

int enque_circular_queue(struct CircularQueue*,int);

int deque_circular_queue(struct CircularQueue*);

int isCircularQueueFull(struct CircularQueue* );

int isCircularQueueEmpty(struct CircularQueue*);

void print_circular_queue(struct CircularQueue*);

int resize(struct CircularQueue*);



struct Queue* create_empty_queue(int);

int enque(struct Queue*,int);

int deque(struct Queue*);

int isQueueFull(struct Queue* );

int isQueueEmpty(struct Queue*);

void print_queue(struct Queue*);
