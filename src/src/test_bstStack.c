#define EXIT_STATUS 0
#include<stdlib.h>
#include<stdio.h>
#include "../header/stack_bst.h"
#include "../header/BST.h"
int main(){

    struct Bst*root = create_node(5);

struct Bst*left=create_node(4);

struct Bst*right = create_node(7);

root->left_subtree=left;
root->right_subtree=right;


//creatng stack 

struct stackBst*stack  = init_stackbst(10);

push(stack, root);

push(stack,left);

push(stack,right);

logStackBst(stack);

return EXIT_STATUS;

}



