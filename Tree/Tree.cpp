#include <iostream>
#include "Tree.h"

using namespace std;

Tree::Tree(){
    this->root = NULL;
}

void Tree::insertNode(int data){
    Node* newNode = new Node(data);
    if(this->root == NULL){
        this->root = newNode;
    } else {
        Node* temp = this->root;
        while(temp != NULL){
            if(data < temp->data){
                if(temp->left == NULL){
                    temp->left = newNode;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if(temp->right == NULL){
                    temp->right = newNode;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
}

void Tree::deleteNode(int data){
    if(this->root == NULL){
        cout << "Tree is empty" << endl;
    } else {
        Node* temp = this->root;
        Node* prev = NULL;
        while(temp->data != data){
            prev = temp;
            if(data < temp->data){
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        if(temp == this->root){
            this->root = NULL;
            delete temp;
        } else {
            if(temp->left == NULL && temp->right == NULL){
                if(prev->left == temp){
                    prev->left = NULL;
                } else {
                    prev->right = NULL;
                }
                delete temp;
            } else if(temp->left == NULL){
                if(prev->left == temp){
                    prev->left = temp->right;
                } else {
                    prev->right = temp->right;
                }
                delete temp;
            } else if(temp->right == NULL){
                if(prev->left == temp){
                    prev->left = temp->left;
                } else {
                    prev->right = temp->left;
                }
                delete temp;
            } else {
                Node* min = temp->right;
                while(min->left != NULL){
                    min = min->left;
                }
                int minData = min->data;
                deleteNode(minData);
                temp->data = minData;
            }
        }
    }
}

void Tree::findNode(int data){
    if(this->root == NULL){
        cout << "Tree is empty" << endl;
    } else {
        Node* temp = this->root;
        while(temp->data != data){
            if(data < temp->data){
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        cout << "Data found: " << temp->data << endl;
    }
}

void Tree::preOrder(Node* node){
    if(node != NULL){
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void Tree::inOrder(Node* node){
    if(node != NULL){
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void Tree::postOrder(Node* node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main(){
    Tree tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(7);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(8);
    tree.inOrder(tree.root);
    tree.preOrder(tree.root);
    tree.postOrder(tree.root);
}