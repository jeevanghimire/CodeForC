#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct NodeIndicator
{
  int data;
  struct NodeIndicator *next;
} NodeIndicator;

// Define the structure of a linked list
typedef struct LinkedList
{
  NodeIndicator *head;
} LinkedListIndicator;

NodeIndicator *CreateNewNode(int a)
{
  NodeIndicator *newNode = (NodeIndicator *)malloc(sizeof(NodeIndicator));
  newNode->data = a;
  newNode->next = NULL;
  return newNode;
}

void printLinkList(LinkedListIndicator *l)
{
  NodeIndicator *temp = l->head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main()
{

  LinkedListIndicator l1 = {NULL};
  NodeIndicator *temp;
  for (int i = 0; i < 25; i++)
  {
    temp = CreateNewNode(i);
    temp->next = l1.head;
    l1.head = temp;
  }
  printLinkList(&l1);

  return 0;
}