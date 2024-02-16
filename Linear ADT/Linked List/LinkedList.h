#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct Node *List;

List insertLL(List, int);
List deleteLL(List, int);
int inLL(List, int);
void freeLL(List);
void showLL(List);
int sizeLL(List);

#endif