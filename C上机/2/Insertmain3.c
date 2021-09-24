#include "InsertHead.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Start with the empty list */
  Node* head = NULL;
 
  // Insert 6.  So linked list becomes 6->NULL
  AddNodeInEnd(&head, 6);
 
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  InsertAtBegin(&head, 7);
 
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  InsertAtBegin(&head, 1);
 
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  AddNodeInEnd(&head, 4);
 
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  InsertAfter(head->next, 8);
 
  printf("Created Linked list is: ");
  PrintList(head);
  printf("\n");
 
  return 0;
}