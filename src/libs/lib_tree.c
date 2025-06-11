#include "../header/binary_tree.h"
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>


 struct BinaryTree *  create_binary_tree(int data){

struct BinaryTree*root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree*));


root->data=data;

return root;



}

int isLeafNode(struct BinaryTree *root){

    return (root->left_subtree==NULL && root->right_subtree==NULL); 

}


int height(struct BinaryTree *root){
    
if(isLeafNode(root) || root==NULL){

    return 0;
}else {

    return 1+ max(height(root->left_subtree),height(root->right_subtree));
}
}


int max(int n1,int n2){

    int max = (n1>=n2)?n1:n2;
    return max;


}
