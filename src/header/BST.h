#ifndef BST_H_INCLUDED

#define BST_H_INCLUDED


struct Bst{

    struct Bst*left_subtree;
    struct Bst*right_subtree;
    int data;

};

struct Bst* create_node(int);

void in_order(struct Bst*);//

int isLeafNode(struct Bst*); // is given node a leaf node

struct Bst* search(struct Bst*,int);// searches given key

struct Bst* delete(struct Bst*); // delete given key

int update(struct Bst*,int); //update given key

int insert(struct Bst*,int); // insert 




#endif // 

