#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool isEmpty(Node* top){
    return top == NULL;
};

void push(Node* &top, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
};

Node* pop(Node* &top){
    if(isEmpty(top)){
        std::cout << "Stack is empty" << std::endl;
    } else {
        Node* temp = top;
        top = top->next;
        return temp;
    }
};

void printStack(Node* top){
    if(isEmpty(top)){
        std::cout << "Stack is empty" << std::endl;
    } else {
        Node* temp = top;
        while(temp != NULL){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Node* top = NULL;
    push(top, 1);
    push(top, 2);
    push(top, 3);
    push(top, 4);
    push(top, 5);
    printStack(top);
    pop(top);
    printStack(top);
}