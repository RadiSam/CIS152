#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<btnodes.h>

//Tree class that uses node class to act as binary tree for plinko
class binarytree {
private:
    btnodes* root;
public:
    //root node set null in constructor
    binarytree();
    //getter
    btnodes* getRoot() const;
    // inserts nodes into tree based on direction and value
    void insert(btnodes* value, int direction);
    // checks if tree is empty
    bool isEmpty();
    //inorder print to string
    string inorderPrint(btnodes* root);
};

#endif // BINARYTREE_H
