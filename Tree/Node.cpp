#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}