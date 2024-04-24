#include<binarytree.h>

//root node set null in constructor
binarytree::binarytree(){
    root = NULL;
}
//getter
btnodes* binarytree::getRoot() const {
    return root;
}
// inserts nodes into tree based on scaling data
void binarytree::insert(btnodes* value, int direction) {
    //case of first node entered
    if (root == NULL) {
        root = value;
    }//sets left sub tree
    else if (direction == 0){
        //local Nodes
        btnodes* temp = value;
        btnodes* current = root;
        btnodes* parent = NULL;
        while(1) {
            parent = current;
            //left tree entered
            if ((value->getScaleNum()) < (current->getScaleNum())) {
                current = current->getLeft();
                if(current == NULL) {
                    parent->setLeft(temp);
                    return;
                }
            }
            //right tree entered
            else {
                current = current->getRight();
                if(current == NULL) {
                    parent->setRight(temp);
                    return;
                }
            }
        }
    }//sets right sub tree
    else {
        btnodes* temp = value;
        btnodes* current = root;
        btnodes* parent = NULL;
        while(1) {
            parent = current;
            //left tree entered
            if ((value->getScaleNum()) > (current->getScaleNum())) {
                current = current->getLeft();
                if(current == NULL) {
                    parent->setLeft(temp);
                    return;
                }
            }
            //right tree entered
            else {
                current = current->getRight();
                if(current == NULL) {
                    parent->setRight(temp);
                    return;
                }
            }
        }
    }
}
// return true when tree is empty by looking at root value
bool binarytree::isEmpty() {
    return (root == NULL);
}
//inorder type print that takes root node and returns node values recursively
string binarytree::inorderPrint(btnodes* root) {
    string result = "";
    if (root != NULL) {
        result.append(inorderPrint(root->getLeft()));
        result.append(to_string(root->getScaleNum()) + " ");
        result.append(inorderPrint(root->getRight()));
    }
    return result;
}
