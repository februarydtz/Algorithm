#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isEmpty(Node* head){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
};

void insertNode(Node* &head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(head)){
        head = newNode;
    } else {
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

void deleteNode(Node* &head, int data){
    if(isEmpty(head)){
        cout << "List is empty" << endl;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while(temp->data != data){
            prev = temp;
            temp = temp->next;
        }
        if(temp == head){
            head = head->next;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }
};

void findNode(Node* head, int data){
    if(isEmpty(head)){
        cout << "List is empty" << endl;
    } else {
        Node* temp = head;
        while(temp->data != data){
            temp = temp->next;
        }
        cout << "Data found: " << temp->data << endl;
    }
};

void printList(Node* head){
    if(isEmpty(head)){
        cout << "List is empty" << endl;
    } else {
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    printList(head);
    deleteNode(head, 3);
    printList(head);
    findNode(head, 4);
    return 0;
}