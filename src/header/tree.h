#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct Tree {
    int data;
    struct Tree*LEFT_SUBTREE;
    struct Tree*RIGHT_SUBTREE;
    
};

struct Tree* createEmptyTree();

int Height(struct Tree*);

void inOrder(struct Tree*);
void preOrder(struct Tree*);
void postOrder(struct Tree*);


#endif // !TREE_H_INCLUDED



