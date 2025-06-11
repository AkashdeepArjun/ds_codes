#include "../header/BST.h"
#include <malloc.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
#define DEFAULT_SIZE 10
 struct Bst* create_node(int data){

     struct Bst*new_node = (struct Bst*)malloc(sizeof(struct Bst*));
    
     new_node->left_subtree=NULL;
     new_node->right_subtree=NULL;

     return new_node;
 }

struct Bst* search(struct Bst*root,int key){
    
    if(root==NULL){
    
        return NULL;
    }else if(key==root->data){
        return root;
    }else if(key>root->data){
        return search(root->right_subtree,key);
    }else{
        return search(root->left_subtree,key);
    }
}









