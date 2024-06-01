#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
  int data;
  struct Node *next;
}node_t;

// Function to reverse the linked list
node_t *reverseLinkedList(node_t *head)
{
  node_t *prev = NULL;
  node_t *current = head;
  node_t *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;
}

node_t *CreateNewNodes(int data)
{
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
// Function to print the linked list
void printLinkedList(struct Node *head)
{
  node_t *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}



// Main function
int main()
{
  node_t *head = CreateNewNodes(1);
  head->next = CreateNewNodes(2);
  head->next->next = CreateNewNodes(3);
  head->next->next->next = CreateNewNodes(4);
  
  printf("Original linked list: ");
  printLinkedList(head);

  head = reverseLinkedList(head);

  printf("Reversed linked list: ");
  printLinkedList(head);

  return 0;
}
