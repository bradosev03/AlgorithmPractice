
#include "node.h"
#include "stdlib.h"
#include "stdio.h"
#include <math.h>


int isPalindrome(Node *head, Node *tail){
  while (head != NULL && tail != NULL){
      if (head->c != tail->c){
        return 0;
      }//end
      else{
        head = head->next;
        tail = tail->next;
      }//end else
  }//end while loop
  return 1;
}//end

void palindromeEven(Node *palindrome, char* word, int size){
    Node *head = malloc(sizeof(Node));
    Node *tail = malloc(sizeof(Node));
    head->c = '\0';
    tail->c = '\0';
    head->next = NULL; //must set them equal to NULL in order for proper insertion
    tail->next = NULL; //must set them equal to NULL in order for proper insertion
    Node *current = palindrome;
    int count = 0;
    while (current != NULL){
      count++;
      if (count <= (int)ceil((double)size/2)){
        insertLast(head, current->c);
        current = current->next;
      }//end
      else if (count > (int)ceil((double)size/2)){
        insertLast(tail, current->c);
        current = current->next;
      }//end if
    }//end while
    int result = isPalindrome(head,tail);
    printf("Is '%s' A Palindrome? %s\n",word,result==1?"Yes!": "No!");
}//end

void palindromeOdd(Node *palindrome, char *word, int size){
    Node *head = malloc(sizeof(Node));
    Node *tail = malloc(sizeof(Node));
    head->c = '\0';
    tail->c = '\0';
    head->next = NULL; //must set them equal to NULL in order for proper insertion
    tail->next = NULL; //must set them equal to NULL in order for proper insertion
    Node *current = palindrome;
    printf("size: %d\n",size);
    int count = 0;
    while (current != NULL){
      count++;
      if (count == (int)ceil((double)size/2)){
          current = current->next;
      }//end
      else if (count < (int)ceil((double)size/2)){
        insertLast(head, current->c);
        printf("Insertion Complete\n");
        current = current->next;
      }//end
      else if (count > (int)ceil((double)size/2)){
        insertFirst(&tail, current->c);
        current = current->next;
      }//end if
    }//end
    int result = isPalindrome(head,tail);
    printf("Is '%s' A Palindrome? %s\n",word,result==1?"Yes!": "No!");
}//end

void palindromeSolver(char *pal){
    Node *palindrome = malloc(sizeof(Node));
    int i;
    for (i = 0; i < strlen(pal); i++){
      insertLast(palindrome, pal[i]);
    }//end
    Node *cnt = palindrome;
    int size = length(cnt);
    printf("size: %d\n",size);
    int count = 0;
    if (size % 2 == 1){
      palindromeOdd(palindrome,pal,size);
    }//end
    else{
      palindromeEven(palindrome,pal,size);
    }//end else
}//end

void usage(char **argv){
  printf("Usage\n");
  printf("---------------------\n");
  printf("Palindrome Check\n");
  printf("%s -t string\n",argv[0]);
  printf("---------------------\n");
}//end


int main(int argc, char **argv){
  printf("Palindrome Solver:\n");
  if (argc < 3){
    printf("Enter a valid string\n");
    usage(argv);
    exit(0);
  }//end
  else{
    palindromeSolver(argv[2]);
  }//end
}//end
