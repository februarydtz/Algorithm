#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
public:
    Node* root;

public:
    Tree();
    void insertNode(int data);
    void deleteNode(int data);
    void findNode(int data);
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);
};

#endif // TREE_H
