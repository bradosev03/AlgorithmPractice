
#include "node.h"
#include "stdlib.h"
#include "stdio.h"

/*
 */
void insertFirst(Node **head, char c){
    Node *h = malloc(sizeof(Node));
    h = *head;
    if (h->c == '\0'){
      h->c = c;
      h->next = NULL;
    }//end
    else{
      Node *new_node;
      new_node = malloc(sizeof(Node));
      new_node->c = c;
      new_node->next = *head;
      *head = new_node;
    }//end
}//end insertFirst
/* //TODO:
 * Check if Head itself is NULL;
 * If head is NULL Make new node head
 * else iterate to the last and check;
 */
void insertLast(Node *head, char c){
   if (head->c == '\0'){ // null terminator signifies no character in list
     head->c = c;
     head->next = NULL;
   }//end
   else{
     Node *current = head;
     while (current->next != NULL) {
         current = current->next;
     }//end while loop
     /* now we can add a new variable */
     current->next = malloc(sizeof(Node));
     current->next->c = c;
     current->next->next = NULL;
   }//end
}//end insertLast
/**/
void printList(Node *head){
    Node *current = head;
    if (current == NULL){
      printf("The Node List is Empty!\n");
    }//end if
    else{
      while (current != NULL) {
          printf("%c\n", current->c);
          current = current->next;
      }//end while loop
    }//end else
}//end printList

int length(Node *head){
    Node *current =head;
    int length = 0;
    while (current != NULL){
      length++;
      current = current->next;
    }//end
    return length;
}//end length
