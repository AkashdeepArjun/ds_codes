#ifndef BinaryTree_h_included
#define BinaryTree_h_included

struct BinaryTree {
    int data;
    struct BinaryTree*left_subtree;
    struct BinaryTree*right_subtree;
    
};

struct BinaryTree* create_binary_tree(int); 
int max(int,int);
int height(struct BinaryTree*);
void level_order(struct BinaryTree*);
void inorder(struct BinaryTree*);
void preorder(struct BinaryTree*);
void postorder(struct BinaryTree*);


#endif // !BinaryTree_h_included
//
// forget the log query on demand logic ... query suggestions not showing first we fix that then we will get back to this one
