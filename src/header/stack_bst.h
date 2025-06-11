#include "../header/BST.h"
#ifndef STACK_BST_H_INCLUDED
#define STACK_BST_H_INCLUDED

struct stackBst {

    int TOP;
    int CAPACITY;
    struct Bst**elements;

}; 

struct stackBst* init_stackbst(int );
int push(struct stackBst* ,struct Bst*);
struct Bst* pop(struct stackBst*);
int isBstStackFull(struct stackBst*);
int isBstStackEmpty(struct stackBst*);
void logStackBst(struct stackBst*);




#endif // !STACK_BST_H_INCLUDED






