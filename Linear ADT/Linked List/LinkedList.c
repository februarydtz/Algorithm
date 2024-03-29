#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node* createNode(int v) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->v = v;
    n->next = NULL;
    return n;
}

void destroyNode(Node *n) {
    free(n);
}

List insertLL(List l, int v) {
    Node* n = createNode(v);
    Node* temp = l;
    if (l == NULL) {
        l = n;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
    return l;
}

List deleteLL(List l, int v) {
    Node* temp = l;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->v == v) {
            if (prev == NULL) {
                l = temp->next;
            } else {
                prev->next = temp->next;
            }
            destroyNode(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return l;
}

int inLL(List l, int v){
    Node* temp = l;
    while (temp != NULL) {
        if (temp->v == v) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void freeLL(List l) {
    Node* temp = l;
    while (temp != NULL) {
        Node* next = temp->next;
        destroyNode(temp);
        temp = next;
    }
}

void showLL(List l) {
    Node* temp = l;
    while (temp != NULL) {
        printf("%d ", temp->v);
        temp = temp->next;
    }
    printf("\n");
}

void reverseLL(List l) {
    Node* prev = NULL;
    Node* current = l;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    l = prev;
}

int sizeLL(List l) {
    Node* temp = l;
    int size = 0;
    if (temp == NULL) {
        return 0;
    } else {
        return 1 + sizeLL(temp->next);
    }
}

int main() {
    List l = NULL;
    l = insertLL(l, 1);
    l = insertLL(l, 2);
    l = insertLL(l, 3);
    l = insertLL(l, 4);
    l = insertLL(l, 5);
    showLL(l);
    l = deleteLL(l, 3);
    showLL(l);
    printf("%d\n", inLL(l, 3));
    printf("%d\n", inLL(l, 4));
    printf("%d\n", sizeLL(l));
    freeLL(l);
    return 0;
}