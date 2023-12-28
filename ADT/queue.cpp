#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool isEmpty(Node* top){
    return top == NULL;
};

void enqueue(Node* &front, Node* &rear, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(front)){
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
};

Node* dequeue(Node* &front, Node* &rear){
    if(isEmpty(front)){
        std::cout << "Queue is empty" << std::endl;
    } else {
        Node* temp = front;
        front = front->next;
        return temp;
    }
};

void printQueue(Node* front){
    if(isEmpty(front)){
        std::cout << "Queue is empty" << std::endl;
    } else {
        Node* temp = front;
        while(temp != NULL){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    Node* front = NULL;
    Node* rear = NULL;
    enqueue(front, rear, 1);
    enqueue(front, rear, 2);
    enqueue(front, rear, 3);
    enqueue(front, rear, 4);
    enqueue(front, rear, 5);
    printQueue(front);
    dequeue(front, rear);
    printQueue(front);
}