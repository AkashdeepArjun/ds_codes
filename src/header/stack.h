#ifndef STACK_H_INCLDUED
#define STACK_H_INCLDUED


struct Stack {
   int top;
   int *elements;
   int capacity;

};

struct Stack* createStack(int );

int push(struct Stack*,int);

int pop(struct Stack*);

void log_stack(struct Stack*);

void delete_stack(struct Stack*);


#endif // STACK_H_INCLDUED


