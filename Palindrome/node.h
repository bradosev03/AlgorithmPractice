#ifndef NODE_H
#define NODE_H

typedef struct Node_T{
  char c;
  struct Node_T *next;
}Node;


void insertFirst(Node **head, char c);
void insertLast(Node *head, char c);
void printList(Node *head);
int length(Node *head);


#endif
